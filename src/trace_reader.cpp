#include <cassert>
#include <iostream>

#include <local_reader.hpp>
#include <trace_reader.hpp>

TraceReader::TraceReader(const std::string &path, Otf2Writer &writer,
                         size_t nthreads)
    : m_writer(writer),
      m_reader(OTF2_Reader_Open(path.c_str()), OTF2_Reader_Close),
      m_location_count(0), m_thread_count(nthreads) {
    OTF2_Reader_SetSerialCollectiveCallbacks(m_reader.get());
    OTF2_Reader_GetNumberOfLocations(m_reader.get(), &m_location_count);

    read_definitions();
}
// TODO name it process_events??
void TraceReader::read() {
    std::vector<std::thread> workers;

    size_t locations_per_thread = m_locations.size() / m_thread_count;
    size_t rest_locations =
        m_locations.size() - locations_per_thread * m_thread_count;

    std::vector<size_t> thread_location_count(m_thread_count,
                                              locations_per_thread);
    for (int i = 0; rest_locations > 0; rest_locations--, i++) {
        thread_location_count[i % m_thread_count]++;
    }

    auto src_begin = m_locations.begin();
    for (size_t i = 0; i < thread_location_count.size(); i++) {
        auto thread_locations = std::vector<size_t>(
            src_begin, src_begin + thread_location_count[i]);
        workers.emplace_back(LocalReader(), m_reader.get(), thread_locations);
        src_begin += thread_location_count[i];
    }
    for (auto &w : workers) {
        w.join();
    }
}

void TraceReader::read_definitions() {
    OTF2_GlobalDefReader *global_def_reader =
        OTF2_Reader_GetGlobalDefReader(m_reader.get());

    // TODO unique pointer
    OTF2_GlobalDefReaderCallbacks *def_callbacks =
        OTF2_GlobalDefReaderCallbacks_New();

    OTF2_GlobalDefReaderCallbacks_SetClockPropertiesCallback(
        def_callbacks, definition::ClockPropertiesCb);

    OTF2_GlobalDefReaderCallbacks_SetParadigmCallback(def_callbacks,
                                                      definition::ParadigmCb);

    OTF2_GlobalDefReaderCallbacks_SetParadigmPropertyCallback(
        def_callbacks, definition::ParadigmPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetIoParadigmCallback(
        def_callbacks, definition::IoParadigmCb);

    OTF2_GlobalDefReaderCallbacks_SetStringCallback(def_callbacks,
                                                    definition::StringCb);

    OTF2_GlobalDefReaderCallbacks_SetAttributeCallback(def_callbacks,
                                                       definition::AttributeCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeCallback(
        def_callbacks, definition::SystemTreeNodeCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationGroupCallback(
        def_callbacks, definition::LocationGroupCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationCallback(def_callbacks,
                                                      definition::LocationCb);

    OTF2_GlobalDefReaderCallbacks_SetRegionCallback(def_callbacks,
                                                    definition::RegionCb);

    OTF2_GlobalDefReaderCallbacks_SetCallsiteCallback(def_callbacks,
                                                      definition::CallsiteCb);

    OTF2_GlobalDefReaderCallbacks_SetCallpathCallback(def_callbacks,
                                                      definition::CallpathCb);

    OTF2_GlobalDefReaderCallbacks_SetGroupCallback(def_callbacks,
                                                   definition::GroupCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricMemberCallback(
        def_callbacks, definition::MetricMemberCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricClassCallback(
        def_callbacks, definition::MetricClassCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricInstanceCallback(
        def_callbacks, definition::MetricInstanceCb);

    OTF2_GlobalDefReaderCallbacks_SetCommCallback(def_callbacks,
                                                  definition::CommCb);

    OTF2_GlobalDefReaderCallbacks_SetParameterCallback(def_callbacks,
                                                       definition::ParameterCb);

    OTF2_GlobalDefReaderCallbacks_SetRmaWinCallback(def_callbacks,
                                                    definition::RmaWinCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricClassRecorderCallback(
        def_callbacks, definition::MetricClassRecorderCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodePropertyCallback(
        def_callbacks, definition::SystemTreeNodePropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeDomainCallback(
        def_callbacks, definition::SystemTreeNodeDomainCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationGroupPropertyCallback(
        def_callbacks, definition::LocationGroupPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationPropertyCallback(
        def_callbacks, definition::LocationPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetCartDimensionCallback(
        def_callbacks, definition::CartDimensionCb);

    OTF2_GlobalDefReaderCallbacks_SetCartTopologyCallback(
        def_callbacks, definition::CartTopologyCb);

    OTF2_GlobalDefReaderCallbacks_SetCartCoordinateCallback(
        def_callbacks, definition::CartCoordinateCb);

    OTF2_GlobalDefReaderCallbacks_SetSourceCodeLocationCallback(
        def_callbacks, definition::SourceCodeLocationCb);

    OTF2_GlobalDefReaderCallbacks_SetCallingContextCallback(
        def_callbacks, definition::CallingContextCb);

    OTF2_GlobalDefReaderCallbacks_SetCallingContextPropertyCallback(
        def_callbacks, definition::CallingContextPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetInterruptGeneratorCallback(
        def_callbacks, definition::InterruptGeneratorCb);

    OTF2_GlobalDefReaderCallbacks_SetIoFilePropertyCallback(
        def_callbacks, definition::IoFilePropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetIoRegularFileCallback(
        def_callbacks, definition::IoRegularFileCb);

    OTF2_GlobalDefReaderCallbacks_SetIoDirectoryCallback(
        def_callbacks, definition::IoDirectoryCb);

    OTF2_GlobalDefReaderCallbacks_SetIoHandleCallback(def_callbacks,
                                                      definition::IoHandleCb);

    OTF2_GlobalDefReaderCallbacks_SetIoPreCreatedHandleStateCallback(
        def_callbacks, definition::IoPreCreatedHandleStateCb);

    OTF2_GlobalDefReaderCallbacks_SetCallpathParameterCallback(
        def_callbacks, definition::CallpathParameterCb);

    OTF2_Reader_RegisterGlobalDefCallbacks(m_reader.get(), global_def_reader,
                                           def_callbacks, this);

    OTF2_GlobalDefReaderCallbacks_Delete(def_callbacks);

    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions(m_reader.get(), global_def_reader,
                                         &definitions_read);

    for (OTF2_LocationRef location : m_locations) {
        OTF2_Reader_SelectLocation(m_reader.get(), location);
    }

    bool def_files_opened =
        OTF2_Reader_OpenDefFiles(m_reader.get()) == OTF2_SUCCESS;

    for (OTF2_LocationRef location : m_locations) {
        if (def_files_opened) {
            OTF2_DefReader *def_reader =
                OTF2_Reader_GetDefReader(m_reader.get(), location);
            if (def_reader) {
                uint64_t def_reads = 0;
                OTF2_Reader_ReadAllLocalDefinitions(m_reader.get(), def_reader,
                                                    &def_reads);
                OTF2_Reader_CloseDefReader(m_reader.get(), def_reader);
            }
        }
    }

    if (def_files_opened) {
        OTF2_Reader_CloseDefFiles(m_reader.get());
    }

    OTF2_Reader_CloseGlobalDefReader(m_reader.get(), global_def_reader);
}