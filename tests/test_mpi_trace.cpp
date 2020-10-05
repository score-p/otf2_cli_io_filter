#include <filesystem>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "itest_handler.hpp"
#include <trace_reader.hpp>
#include <trace_writer.hpp>

#include "mpi_config.hpp"

namespace fs = std::filesystem;

class TestHandler : public ITestHandler
{
    using RegionEventTuble     = std::tuple<OTF2_LocationRef, OTF2_TimeStamp, OTF2_RegionRef>;
    using CollectiveEventTuple = std::tuple<OTF2_LocationRef, OTF2_TimeStamp>;

  public:
    virtual void
    handleEnterEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) override
    {
        m_enter_events.push_back(std::make_tuple(location, time, region));
    }

    virtual void
    handleLeaveEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) override
    {
        m_leave_events.push_back(std::make_tuple(location, time, region));
    }

    virtual void
    handleMpiCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time, OTF2_AttributeList *attributes) override
    {
        m_coll_begin_events.push_back(std::make_tuple(location, time));
    }

    virtual void
    handleMpiCollectiveEndEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CollectiveOp   collectiveOp,
                                OTF2_CommRef        communicator,
                                uint32_t            root,
                                uint64_t            sizeSent,
                                uint64_t            sizeReceived) override
    {
        m_coll_end_events.push_back(std::make_tuple(location, time));
    }

    void
    equals(const TestHandler &other) const
    {
        REQUIRE(m_enter_events == other.m_enter_events);
        REQUIRE(m_leave_events == other.m_leave_events);
        REQUIRE(m_coll_begin_events == other.m_coll_begin_events);
        REQUIRE(m_coll_end_events == other.m_coll_end_events);
    }

  private:
    std::vector<RegionEventTuble>     m_enter_events;
    std::vector<RegionEventTuble>     m_leave_events;
    std::vector<CollectiveEventTuple> m_coll_begin_events;
    std::vector<CollectiveEventTuple> m_coll_end_events;
};

TEST_CASE("Test trace generation for MPI traces.", "[trace_mpi]")
{
    std::stringstream ss;
    ss << MpiConfigTracePath << '/' << MpiConfigTraceName << ".otf2";

    fs::path input_trace(ss.str());
    if (!fs::exists(input_trace))
    {
        throw std::runtime_error("Input trace was not generated.");
    }

    /*
     * Read input trace and store events.
     */
    TestHandler source_handler;
    {
        TraceReader tr(input_trace.string(), source_handler, 1);
        tr.read();
    }

    /*
     * Copy input trace
     */
    fs::path output_trace("output_trace");
    {
        TraceWriter tw(output_trace.string());
        std::string trace_name = "/";
        trace_name += tw.traceName();
        trace_name += ".otf2";

        output_trace += trace_name;

        TraceReader tr(input_trace.string(), tw, 1);
        tr.read();
    }

    REQUIRE(fs::exists(output_trace));
    /*
     * Read output trace and store events.
     */
    TestHandler target_handler;
    {
        TraceReader tr(output_trace.string(), target_handler, 1);
        tr.read();
    }

    source_handler.equals(target_handler);

    std::error_code ec;
    auto            err = fs::remove_all(output_trace.parent_path(), ec);
    REQUIRE(err != static_cast<std::uintmax_t>(-1));

    err = fs::remove_all(input_trace.parent_path(), ec);
    REQUIRE(err != static_cast<std::uintmax_t>(-1));
}
