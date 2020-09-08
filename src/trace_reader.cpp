#include <cassert>
#include <iostream>

#include <local_reader.hpp>
#include <trace_reader.hpp>

TraceReader::TraceReader(const std::string &path, Otf2Handler &handler, size_t nthreads)
    : m_handler(handler), m_reader(OTF2_Reader_Open(path.c_str()), OTF2_Reader_Close), m_location_count(0),
      m_thread_count(nthreads)
{
    OTF2_Reader_SetSerialCollectiveCallbacks(m_reader.get());
    OTF2_Reader_GetNumberOfLocations(m_reader.get(), &m_location_count);

    read_definitions();
}
// TODO name it process_events??
void
TraceReader::read()
{
    std::vector<std::thread> workers;

    size_t locations_per_thread = m_locations.size() / m_thread_count;
    size_t rest_locations       = m_locations.size() - locations_per_thread * m_thread_count;

    std::vector<size_t> thread_location_count(m_thread_count, locations_per_thread);
    for (int i = 0; rest_locations > 0; rest_locations--, i++)
    {
        thread_location_count[i % m_thread_count]++;
    }

    auto src_begin = m_locations.begin();
    for (size_t i = 0; i < thread_location_count.size(); i++)
    {
        auto thread_locations = std::vector<size_t>(src_begin, src_begin + thread_location_count[i]);
        workers.emplace_back(LocalReader(m_handler), m_reader.get(), thread_locations);
        src_begin += thread_location_count[i];
    }
    for (auto &w : workers)
    {
        w.join();
    }
}

void
TraceReader::read_definitions()
{
    OTF2_GlobalDefReader *global_def_reader = OTF2_Reader_GetGlobalDefReader(m_reader.get());

    // TODO unique pointer
    OTF2_GlobalDefReaderCallbacks *def_callbacks = OTF2_GlobalDefReaderCallbacks_New();

    OTF2_GlobalDefReaderCallbacks_SetClockPropertiesCallback(def_callbacks, definition::GlobalClockPropertiesCb);

    OTF2_GlobalDefReaderCallbacks_SetParadigmCallback(def_callbacks, definition::GlobalParadigmCb);

    OTF2_GlobalDefReaderCallbacks_SetParadigmPropertyCallback(def_callbacks, definition::GlobalParadigmPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetIoParadigmCallback(def_callbacks, definition::GlobalIoParadigmCb);

    OTF2_GlobalDefReaderCallbacks_SetStringCallback(def_callbacks, definition::GlobalStringCb);

    OTF2_GlobalDefReaderCallbacks_SetAttributeCallback(def_callbacks, definition::GlobalAttributeCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeCallback(def_callbacks, definition::GlobalSystemTreeNodeCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationGroupCallback(def_callbacks, definition::GlobalLocationGroupCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationCallback(def_callbacks, definition::GlobalLocationCb);

    OTF2_GlobalDefReaderCallbacks_SetRegionCallback(def_callbacks, definition::GlobalRegionCb);

    OTF2_GlobalDefReaderCallbacks_SetCallsiteCallback(def_callbacks, definition::GlobalCallsiteCb);

    OTF2_GlobalDefReaderCallbacks_SetCallpathCallback(def_callbacks, definition::GlobalCallpathCb);

    OTF2_GlobalDefReaderCallbacks_SetGroupCallback(def_callbacks, definition::GlobalGroupCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricMemberCallback(def_callbacks, definition::GlobalMetricMemberCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricClassCallback(def_callbacks, definition::GlobalMetricClassCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricInstanceCallback(def_callbacks, definition::GlobalMetricInstanceCb);

    OTF2_GlobalDefReaderCallbacks_SetCommCallback(def_callbacks, definition::GlobalCommCb);

    OTF2_GlobalDefReaderCallbacks_SetParameterCallback(def_callbacks, definition::GlobalParameterCb);

    OTF2_GlobalDefReaderCallbacks_SetRmaWinCallback(def_callbacks, definition::GlobalRmaWinCb);

    OTF2_GlobalDefReaderCallbacks_SetMetricClassRecorderCallback(def_callbacks,
                                                                 definition::GlobalMetricClassRecorderCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodePropertyCallback(def_callbacks,
                                                                    definition::GlobalSystemTreeNodePropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeDomainCallback(def_callbacks,
                                                                  definition::GlobalSystemTreeNodeDomainCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationGroupPropertyCallback(def_callbacks,
                                                                   definition::GlobalLocationGroupPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetLocationPropertyCallback(def_callbacks, definition::GlobalLocationPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetCartDimensionCallback(def_callbacks, definition::GlobalCartDimensionCb);

    OTF2_GlobalDefReaderCallbacks_SetCartTopologyCallback(def_callbacks, definition::GlobalCartTopologyCb);

    OTF2_GlobalDefReaderCallbacks_SetCartCoordinateCallback(def_callbacks, definition::GlobalCartCoordinateCb);

    OTF2_GlobalDefReaderCallbacks_SetSourceCodeLocationCallback(def_callbacks, definition::GlobalSourceCodeLocationCb);

    OTF2_GlobalDefReaderCallbacks_SetCallingContextCallback(def_callbacks, definition::GlobalCallingContextCb);

    OTF2_GlobalDefReaderCallbacks_SetCallingContextPropertyCallback(def_callbacks,
                                                                    definition::GlobalCallingContextPropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetInterruptGeneratorCallback(def_callbacks, definition::GlobalInterruptGeneratorCb);

    OTF2_GlobalDefReaderCallbacks_SetIoFilePropertyCallback(def_callbacks, definition::GlobalIoFilePropertyCb);

    OTF2_GlobalDefReaderCallbacks_SetIoRegularFileCallback(def_callbacks, definition::GlobalIoRegularFileCb);

    OTF2_GlobalDefReaderCallbacks_SetIoDirectoryCallback(def_callbacks, definition::GlobalIoDirectoryCb);

    OTF2_GlobalDefReaderCallbacks_SetIoHandleCallback(def_callbacks, definition::GlobalIoHandleCb);

    OTF2_GlobalDefReaderCallbacks_SetIoPreCreatedHandleStateCallback(def_callbacks,
                                                                     definition::GlobalIoPreCreatedHandleStateCb);

    OTF2_GlobalDefReaderCallbacks_SetCallpathParameterCallback(def_callbacks, definition::GlobalCallpathParameterCb);

    OTF2_Reader_RegisterGlobalDefCallbacks(m_reader.get(), global_def_reader, def_callbacks, this);

    OTF2_GlobalDefReaderCallbacks_Delete(def_callbacks);

    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions(m_reader.get(), global_def_reader, &definitions_read);

    OTF2_Reader_CloseGlobalDefReader(m_reader.get(), global_def_reader);
}