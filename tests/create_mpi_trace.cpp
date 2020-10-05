/*
 * This file is part of the Score-P software (http://www.score-p.org)
 *
 * Copyright (c) 2009-2013,
 * RWTH Aachen University, Germany
 *
 * Copyright (c) 2009-2013,
 * Gesellschaft fuer numerische Simulation mbH Braunschweig, Germany
 *
 * Copyright (c) 2009-2014,
 * Technische Universitaet Dresden, Germany
 *
 * Copyright (c) 2009-2013,
 * University of Oregon, Eugene, USA
 *
 * Copyright (c) 2009-2013,
 * Forschungszentrum Juelich GmbH, Germany
 *
 * Copyright (c) 2009-2013,
 * German Research School for Simulation Sciences GmbH, Juelich/Aachen, Germany
 *
 * Copyright (c) 2009-2013,
 * Technische Universitaet Muenchen, Germany
 *
 * This software may be modified and distributed under the terms of
 * a BSD-style license.  See the COPYING file in the package base
 * directory for details.
 *
 */

#include <algorithm>
#include <array>
#include <cstdint>
#include <filesystem>
#include <sstream>
#include <tuple>
#include <vector>

#include "mpi_config.hpp"

namespace fs = std::filesystem;

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

extern "C"
{
#include <mpi.h>
#include <stdlib.h>
#include <sys/time.h>

#include <otf2/OTF2_MPI_Collectives.h>
#include <otf2/otf2.h>
}

static inline uint64_t
get_ticks()
{
    int            rank   = 0;
    const int      offset = rank * 32;
    struct timeval tp;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    gettimeofday(&tp, 0);
    return (uint64_t)tp.tv_sec * UINT64_C(1000000) + (uint64_t)tp.tv_usec + offset;
}

static inline uint64_t
get_clock_resolution(void)
{
    return UINT64_C(1000000);
}

static OTF2_FlushType
pre_flush(void *userData, OTF2_FileType fileType, OTF2_LocationRef location, void *callerData, bool final)
{
    return OTF2_FLUSH;
}

static OTF2_TimeStamp
post_flush(void *userData, OTF2_FileType fileType, OTF2_LocationRef location)
{
    return get_ticks();
}
extern "C"
{
    static OTF2_FlushCallbacks flush_callbacks = {.otf2_pre_flush = pre_flush, .otf2_post_flush = post_flush};
}

static void
mpi_comm_world_barrier(OTF2_EvtWriter *evt_writer)
{
    OTF2_EvtWriter_Enter(evt_writer, nullptr, get_ticks(), 0 /* region */);
    OTF2_EvtWriter_MpiCollectiveBegin(evt_writer, nullptr, get_ticks());

    MPI_Barrier(MPI_COMM_WORLD);

    OTF2_EvtWriter_MpiCollectiveEnd(evt_writer,
                                    nullptr,
                                    get_ticks(),
                                    OTF2_COLLECTIVE_OP_BARRIER,
                                    0 /* communicator */,
                                    OTF2_UNDEFINED_UINT32 /* root */,
                                    0 /* bytes provided */,
                                    0 /* bytes obtained */);

    OTF2_EvtWriter_Leave(evt_writer, nullptr, get_ticks(), 0 /* region */);
}

constexpr const int N_PINGPONGS = 10;

using SyncTimes = std::tuple<uint64_t, int>;

static SyncTimes
synchronize_with_worker(int worker)
{
    constexpr const int               tag       = 0;
    int                               min_index = 0;
    std::array<uint64_t, N_PINGPONGS> master_send_time;
    std::array<uint64_t, N_PINGPONGS> master_recv_time;

    for (int i = 0; i < N_PINGPONGS; ++i)
    {
        int dummy           = 0;
        master_send_time[i] = get_ticks();
        MPI_Send(&dummy, 1, MPI_INT, worker, tag, MPI_COMM_WORLD);

        MPI_Recv(&dummy, 1, MPI_INT, worker, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        master_recv_time[i] = get_ticks();
    }

    uint64_t ping_pong_time = UINT64_MAX;
    for (int i = 0; i < N_PINGPONGS; ++i)
    {
        uint64_t time_diff = master_recv_time[i] - master_send_time[i];
        if (time_diff < ping_pong_time)
        {
            ping_pong_time = time_diff;
            min_index      = i;
        }
    }
    uint64_t sync_time = master_send_time[min_index] + ping_pong_time / 2;
    return std::make_tuple(sync_time, min_index);
}

static void
synchronize_clocks(int rank, int size, OTF2_DefWriter *writer)
{
    constexpr const int tag    = 0;
    int64_t             offset = 0;
    uint64_t            offset_time;

    if (rank == 0)
    {
        for (int worker = 1; worker < size; ++worker)
        {
            const auto [sync_time, min_index] = synchronize_with_worker(worker);

            MPI_Send(&sync_time, 1, MPI_UINT64_T, worker, tag, MPI_COMM_WORLD);
            MPI_Send(&min_index, 1, MPI_INT, worker, tag, MPI_COMM_WORLD);
        }
        offset_time = get_ticks();
    }
    else
    {
        std::array<uint64_t, N_PINGPONGS> worker_time;
        constexpr const int               master = 0;
        for (int i = 0; i < N_PINGPONGS; ++i)
        {
            int dummy = 0;
            MPI_Recv(&dummy, 1, MPI_INT, master, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            worker_time[i] = get_ticks();
            MPI_Send(&dummy, 1, MPI_INT, master, tag, MPI_COMM_WORLD);
        }

        uint64_t sync_time;
        int      min_index;

        MPI_Recv(&sync_time, 1, MPI_UINT64_T, master, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&min_index, 1, MPI_INT, master, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        offset_time = worker_time[min_index];
        offset      = sync_time - offset_time;
    }

    constexpr const double stddev_not_calculated_yet = 0.0;
    OTF2_DefWriter_WriteClockOffset(writer, offset_time, offset, stddev_not_calculated_yet);
}

static void
create_mpi_trace(int rank, int size, const char *trace_path, const char *trace_name)
{
    OTF2_Archive *archive = OTF2_Archive_Open(trace_path,
                                              trace_name,
                                              OTF2_FILEMODE_WRITE,
                                              1024 * 1024 /* event chunk size */,
                                              4 * 1024 * 1024 /* def chunk size */,
                                              OTF2_SUBSTRATE_POSIX,
                                              OTF2_COMPRESSION_NONE);

    OTF2_Archive_SetFlushCallbacks(archive, &flush_callbacks, nullptr);
    OTF2_MPI_Archive_SetCollectiveCallbacks(archive, MPI_COMM_WORLD, MPI_COMM_NULL);

    OTF2_Archive_OpenEvtFiles(archive);

    OTF2_EvtWriter *evt_writer = OTF2_Archive_GetEvtWriter(archive, rank);

    const uint64_t epoch_start = get_ticks();

    mpi_comm_world_barrier(evt_writer);

    const uint64_t epoch_end = get_ticks();

    OTF2_Archive_CloseEvtWriter(archive, evt_writer);
    OTF2_Archive_CloseEvtFiles(archive);

    OTF2_Archive_OpenDefFiles(archive);
    OTF2_DefWriter *def_writer = OTF2_Archive_GetDefWriter(archive, rank);

    synchronize_clocks(rank, size, def_writer);

    OTF2_Archive_CloseDefWriter(archive, def_writer);
    OTF2_Archive_CloseDefFiles(archive);

    uint64_t global_epoch_start;
    MPI_Reduce(&epoch_start, &global_epoch_start, 1, OTF2_MPI_UINT64_T, MPI_MIN, 0, MPI_COMM_WORLD);
    uint64_t global_epoch_end;
    MPI_Reduce(&epoch_end, &global_epoch_end, 1, OTF2_MPI_UINT64_T, MPI_MAX, 0, MPI_COMM_WORLD);

    if (0 == rank)
    {
        OTF2_GlobalDefWriter *global_def_writer = OTF2_Archive_GetGlobalDefWriter(archive);

        OTF2_GlobalDefWriter_WriteClockProperties(
            global_def_writer, get_clock_resolution(), global_epoch_start, global_epoch_end - global_epoch_start + 1);

        auto get_string_id = [inc = 0](bool create_new_id = true) mutable { return create_new_id ? inc++ : inc; };

        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "Master Thread");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "MPI_Barrier");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "PMPI_Barrier");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "barrier");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "MyHost");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "node");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "MPI");
        OTF2_GlobalDefWriter_WriteString(global_def_writer, get_string_id(), "MPI_COMM_WORLD");

        OTF2_GlobalDefWriter_WriteRegion(global_def_writer,
                                         0 /* id */,
                                         2 /* region name  */,
                                         3 /* alternative name */,
                                         4 /* description */,
                                         OTF2_REGION_ROLE_BARRIER,
                                         OTF2_PARADIGM_MPI,
                                         OTF2_REGION_FLAG_NONE,
                                         7 /* source file */,
                                         0 /* begin lno */,
                                         0 /* end lno */);

        OTF2_GlobalDefWriter_WriteSystemTreeNode(
            global_def_writer, 0 /* id */, 5 /* name */, 6 /* class */, OTF2_UNDEFINED_SYSTEM_TREE_NODE /* parent */);

        std::vector<uint64_t> comm_locations(size);
        std::generate(comm_locations.begin(), comm_locations.end(), [inc = 0]() mutable { return inc++; });

        std::stringstream ss;

        for (uint64_t rank_num : comm_locations)
        {
            ss << "MPI Rank " << rank_num;
            const char *process   = ss.str().c_str();
            const auto  string_id = get_string_id();

            OTF2_GlobalDefWriter_WriteString(global_def_writer, string_id, process);

            OTF2_GlobalDefWriter_WriteLocationGroup(global_def_writer,
                                                    rank_num /* id */,
                                                    string_id /* name */,
                                                    OTF2_LOCATION_GROUP_TYPE_PROCESS,
                                                    0 /* system tree */);

            OTF2_GlobalDefWriter_WriteLocation(global_def_writer,
                                               rank_num /* id */,
                                               1 /* name */,
                                               OTF2_LOCATION_TYPE_CPU_THREAD,
                                               4 /* # events */,
                                               rank_num /* location group */);

            ss.clear();
        }

        OTF2_GlobalDefWriter_WriteGroup(global_def_writer,
                                        0 /* id */,
                                        7 /* name */,
                                        OTF2_GROUP_TYPE_COMM_LOCATIONS,
                                        OTF2_PARADIGM_MPI,
                                        OTF2_GROUP_FLAG_NONE,
                                        size,
                                        comm_locations.data());

        OTF2_GlobalDefWriter_WriteGroup(global_def_writer,
                                        1 /* id */,
                                        0 /* name */,
                                        OTF2_GROUP_TYPE_COMM_GROUP,
                                        OTF2_PARADIGM_MPI,
                                        OTF2_GROUP_FLAG_NONE,
                                        size,
                                        comm_locations.data());

        OTF2_GlobalDefWriter_WriteComm(
            global_def_writer, 0 /* id */, 8 /* name */, 1 /* group */, OTF2_UNDEFINED_COMM /* parent */);

        OTF2_Archive_CloseGlobalDefWriter(archive, global_def_writer);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    OTF2_Archive_Close(archive);
}

TEST_CASE("Test created MPI trace.", "[create_trace_mpi]")
{
    std::stringstream ss;
    ss << MpiConfigTracePath << "/" << MpiConfigTraceName << ".otf2";
    fs::path trace_file_path(ss.str());
    REQUIRE(fs::exists(trace_file_path) == true);
}

int
main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int size;
    int rank;
    int result = 0;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    create_mpi_trace(rank, size, MpiConfigTracePath, MpiConfigTraceName);

    if (0 == rank)
    {
        result = Catch::Session().run(argc, argv);
    }

    MPI_Finalize();
    return result;
}
