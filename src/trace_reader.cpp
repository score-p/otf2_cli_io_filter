#include <cassert>
#include <iostream>

#include "trace_reader.hpp"

TraceReader::TraceReader(const std::string &path, Otf2Writer & writer)
:m_writer(writer),
m_reader(OTF2_Reader_Open(path.c_str()), OTF2_Reader_Close),
m_global_event_reader(nullptr,
                      [this](OTF2_GlobalEvtReader *reader){
                          OTF2_Reader_CloseGlobalEvtReader(m_reader.get(), 
                                                           reader);
                      }),
m_location_count(0)
{
    OTF2_Reader_SetSerialCollectiveCallbacks(m_reader.get());
    OTF2_Reader_GetNumberOfLocations(m_reader.get(), &m_location_count);
    m_global_def_reader = OTF2_Reader_GetGlobalDefReader(m_reader.get());
    
    // TODO unique pointer
    OTF2_GlobalDefReaderCallbacks* def_callbacks = OTF2_GlobalDefReaderCallbacks_New();


    OTF2_GlobalDefReaderCallbacks_SetClockPropertiesCallback(def_callbacks, 
                                                          definition::ClockPropertiesCb);


    OTF2_GlobalDefReaderCallbacks_SetParadigmCallback(def_callbacks, 
                                                          definition::ParadigmCb);


    OTF2_GlobalDefReaderCallbacks_SetParadigmPropertyCallback(def_callbacks, 
                                                          definition::ParadigmPropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetIoParadigmCallback(def_callbacks, 
                                                          definition::IoParadigmCb);


    OTF2_GlobalDefReaderCallbacks_SetStringCallback(def_callbacks, 
                                                          definition::StringCb);


    OTF2_GlobalDefReaderCallbacks_SetAttributeCallback(def_callbacks, 
                                                          definition::AttributeCb);


    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeCallback(def_callbacks, 
                                                          definition::SystemTreeNodeCb);


    OTF2_GlobalDefReaderCallbacks_SetLocationGroupCallback(def_callbacks, 
                                                          definition::LocationGroupCb);


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


    OTF2_GlobalDefReaderCallbacks_SetMetricMemberCallback(def_callbacks, 
                                                          definition::MetricMemberCb);


    OTF2_GlobalDefReaderCallbacks_SetMetricClassCallback(def_callbacks, 
                                                          definition::MetricClassCb);


    OTF2_GlobalDefReaderCallbacks_SetMetricInstanceCallback(def_callbacks, 
                                                          definition::MetricInstanceCb);


    OTF2_GlobalDefReaderCallbacks_SetCommCallback(def_callbacks, 
                                                          definition::CommCb);


    OTF2_GlobalDefReaderCallbacks_SetParameterCallback(def_callbacks, 
                                                          definition::ParameterCb);


    OTF2_GlobalDefReaderCallbacks_SetRmaWinCallback(def_callbacks, 
                                                          definition::RmaWinCb);


    OTF2_GlobalDefReaderCallbacks_SetMetricClassRecorderCallback(def_callbacks, 
                                                          definition::MetricClassRecorderCb);


    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodePropertyCallback(def_callbacks, 
                                                          definition::SystemTreeNodePropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeDomainCallback(def_callbacks, 
                                                          definition::SystemTreeNodeDomainCb);


    OTF2_GlobalDefReaderCallbacks_SetLocationGroupPropertyCallback(def_callbacks, 
                                                          definition::LocationGroupPropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetLocationPropertyCallback(def_callbacks, 
                                                          definition::LocationPropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetCartDimensionCallback(def_callbacks, 
                                                          definition::CartDimensionCb);


    OTF2_GlobalDefReaderCallbacks_SetCartTopologyCallback(def_callbacks, 
                                                          definition::CartTopologyCb);


    OTF2_GlobalDefReaderCallbacks_SetCartCoordinateCallback(def_callbacks, 
                                                          definition::CartCoordinateCb);


    OTF2_GlobalDefReaderCallbacks_SetSourceCodeLocationCallback(def_callbacks, 
                                                          definition::SourceCodeLocationCb);


    OTF2_GlobalDefReaderCallbacks_SetCallingContextCallback(def_callbacks, 
                                                          definition::CallingContextCb);


    OTF2_GlobalDefReaderCallbacks_SetCallingContextPropertyCallback(def_callbacks, 
                                                          definition::CallingContextPropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetInterruptGeneratorCallback(def_callbacks, 
                                                          definition::InterruptGeneratorCb);


    OTF2_GlobalDefReaderCallbacks_SetIoFilePropertyCallback(def_callbacks, 
                                                          definition::IoFilePropertyCb);


    OTF2_GlobalDefReaderCallbacks_SetIoRegularFileCallback(def_callbacks, 
                                                          definition::IoRegularFileCb);


    OTF2_GlobalDefReaderCallbacks_SetIoDirectoryCallback(def_callbacks, 
                                                          definition::IoDirectoryCb);


    OTF2_GlobalDefReaderCallbacks_SetIoHandleCallback(def_callbacks, 
                                                          definition::IoHandleCb);


    OTF2_GlobalDefReaderCallbacks_SetIoPreCreatedHandleStateCallback(def_callbacks, 
                                                          definition::IoPreCreatedHandleStateCb);


    OTF2_GlobalDefReaderCallbacks_SetCallpathParameterCallback(def_callbacks, 
                                                          definition::CallpathParameterCb);


    OTF2_Reader_RegisterGlobalDefCallbacks(m_reader.get(),
                                           m_global_def_reader,
                                           def_callbacks,
                                           this);
    
    OTF2_GlobalDefReaderCallbacks_Delete(def_callbacks);

    read_definitions();

    m_global_event_reader.reset(OTF2_Reader_GetGlobalEvtReader(m_reader.get()));
    assert(m_global_event_reader != nullptr);

    // TODO unique pointer
    OTF2_GlobalEvtReaderCallbacks* event_callbacks = OTF2_GlobalEvtReaderCallbacks_New();

    OTF2_Reader_RegisterGlobalEvtCallbacks(m_reader.get(),
                                           m_global_event_reader.get(),
                                           event_callbacks,
                                           this);
    
    // OTF2_GlobalEvtReaderCallbacks_SetEnterCallback(event_callbacks,
    //                                                &Enter_print );    

    OTF2_GlobalEvtReaderCallbacks_Delete(event_callbacks);
}

void
TraceReader::read()
{
    uint64_t events_read = 0;
    OTF2_Reader_ReadAllGlobalEvents(m_reader.get(),
                                    m_global_event_reader.get(),
                                    &events_read);
    std::cout << "Read " << events_read << " events\n"; 
}

void
TraceReader::read_definitions()
{
    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions(m_reader.get(),
                                         m_global_def_reader,
                                         &definitions_read);

    for(OTF2_LocationRef location:  m_locations)
    {
        OTF2_Reader_SelectLocation(m_reader.get(), location);
    }

    bool def_files_opened = OTF2_Reader_OpenDefFiles(m_reader.get()) == OTF2_SUCCESS;
    OTF2_Reader_OpenEvtFiles(m_reader.get());

    for (OTF2_LocationRef location:  m_locations)
    {
        if (def_files_opened)
        {
            OTF2_DefReader* def_reader = OTF2_Reader_GetDefReader(m_reader.get(), location);
            if (def_reader)
            {
                uint64_t def_reads = 0;
                OTF2_Reader_ReadAllLocalDefinitions(m_reader.get(),
                                                    def_reader,
                                                    &def_reads);
                OTF2_Reader_CloseDefReader(m_reader.get(), def_reader);
            }
        }
        [[maybe_unused]]
        OTF2_EvtReader* evt_reader = OTF2_Reader_GetEvtReader(m_reader.get(), location);
    }
    
    if (def_files_opened)
    {
        OTF2_Reader_CloseDefFiles(m_reader.get());
    }
}            