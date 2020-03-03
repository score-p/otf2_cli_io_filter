#include <cassert>
#include <iostream>

#include "trace_reader.hpp"
#include "event_callbacks.hpp"

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


    OTF2_GlobalEvtReaderCallbacks_SetBufferFlushCallback(event_callbacks,
                                                            event::BufferFlushCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMeasurementOnOffCallback(event_callbacks,
                                                            event::MeasurementOnOffCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetEnterCallback(event_callbacks,
                                                            event::EnterCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetLeaveCallback(event_callbacks,
                                                            event::LeaveCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiSendCallback(event_callbacks,
                                                            event::MpiSendCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiIsendCallback(event_callbacks,
                                                            event::MpiIsendCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiIsendCompleteCallback(event_callbacks,
                                                            event::MpiIsendCompleteCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiIrecvRequestCallback(event_callbacks,
                                                            event::MpiIrecvRequestCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiRecvCallback(event_callbacks,
                                                            event::MpiRecvCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiIrecvCallback(event_callbacks,
                                                            event::MpiIrecvCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiRequestTestCallback(event_callbacks,
                                                            event::MpiRequestTestCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiRequestCancelledCallback(event_callbacks,
                                                            event::MpiRequestCancelledCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiCollectiveBeginCallback(event_callbacks,
                                                            event::MpiCollectiveBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMpiCollectiveEndCallback(event_callbacks,
                                                            event::MpiCollectiveEndCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpForkCallback(event_callbacks,
                                                            event::OmpForkCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpJoinCallback(event_callbacks,
                                                            event::OmpJoinCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpAcquireLockCallback(event_callbacks,
                                                            event::OmpAcquireLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpReleaseLockCallback(event_callbacks,
                                                            event::OmpReleaseLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpTaskCreateCallback(event_callbacks,
                                                            event::OmpTaskCreateCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpTaskSwitchCallback(event_callbacks,
                                                            event::OmpTaskSwitchCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetOmpTaskCompleteCallback(event_callbacks,
                                                            event::OmpTaskCompleteCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetMetricCallback(event_callbacks,
                                                            event::MetricCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetParameterStringCallback(event_callbacks,
                                                            event::ParameterStringCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetParameterIntCallback(event_callbacks,
                                                            event::ParameterIntCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetParameterUnsignedIntCallback(event_callbacks,
                                                            event::ParameterUnsignedIntCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaWinCreateCallback(event_callbacks,
                                                            event::RmaWinCreateCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaWinDestroyCallback(event_callbacks,
                                                            event::RmaWinDestroyCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaCollectiveBeginCallback(event_callbacks,
                                                            event::RmaCollectiveBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaCollectiveEndCallback(event_callbacks,
                                                            event::RmaCollectiveEndCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaGroupSyncCallback(event_callbacks,
                                                            event::RmaGroupSyncCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaRequestLockCallback(event_callbacks,
                                                            event::RmaRequestLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaAcquireLockCallback(event_callbacks,
                                                            event::RmaAcquireLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaTryLockCallback(event_callbacks,
                                                            event::RmaTryLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaReleaseLockCallback(event_callbacks,
                                                            event::RmaReleaseLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaSyncCallback(event_callbacks,
                                                            event::RmaSyncCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaWaitChangeCallback(event_callbacks,
                                                            event::RmaWaitChangeCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaPutCallback(event_callbacks,
                                                            event::RmaPutCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaGetCallback(event_callbacks,
                                                            event::RmaGetCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaAtomicCallback(event_callbacks,
                                                            event::RmaAtomicCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaOpCompleteBlockingCallback(event_callbacks,
                                                            event::RmaOpCompleteBlockingCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaOpCompleteNonBlockingCallback(event_callbacks,
                                                            event::RmaOpCompleteNonBlockingCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaOpTestCallback(event_callbacks,
                                                            event::RmaOpTestCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetRmaOpCompleteRemoteCallback(event_callbacks,
                                                            event::RmaOpCompleteRemoteCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadForkCallback(event_callbacks,
                                                            event::ThreadForkCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadJoinCallback(event_callbacks,
                                                            event::ThreadJoinCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadTeamBeginCallback(event_callbacks,
                                                            event::ThreadTeamBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadTeamEndCallback(event_callbacks,
                                                            event::ThreadTeamEndCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadAcquireLockCallback(event_callbacks,
                                                            event::ThreadAcquireLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadReleaseLockCallback(event_callbacks,
                                                            event::ThreadReleaseLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadTaskCreateCallback(event_callbacks,
                                                            event::ThreadTaskCreateCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadTaskSwitchCallback(event_callbacks,
                                                            event::ThreadTaskSwitchCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadTaskCompleteCallback(event_callbacks,
                                                            event::ThreadTaskCompleteCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadCreateCallback(event_callbacks,
                                                            event::ThreadCreateCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadBeginCallback(event_callbacks,
                                                            event::ThreadBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadWaitCallback(event_callbacks,
                                                            event::ThreadWaitCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetThreadEndCallback(event_callbacks,
                                                            event::ThreadEndCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetCallingContextEnterCallback(event_callbacks,
                                                            event::CallingContextEnterCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetCallingContextLeaveCallback(event_callbacks,
                                                            event::CallingContextLeaveCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetCallingContextSampleCallback(event_callbacks,
                                                            event::CallingContextSampleCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoCreateHandleCallback(event_callbacks,
                                                            event::IoCreateHandleCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoDestroyHandleCallback(event_callbacks,
                                                            event::IoDestroyHandleCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoDuplicateHandleCallback(event_callbacks,
                                                            event::IoDuplicateHandleCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoSeekCallback(event_callbacks,
                                                            event::IoSeekCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoChangeStatusFlagsCallback(event_callbacks,
                                                            event::IoChangeStatusFlagsCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoDeleteFileCallback(event_callbacks,
                                                            event::IoDeleteFileCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoOperationBeginCallback(event_callbacks,
                                                            event::IoOperationBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoOperationTestCallback(event_callbacks,
                                                            event::IoOperationTestCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoOperationIssuedCallback(event_callbacks,
                                                            event::IoOperationIssuedCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoOperationCompleteCallback(event_callbacks,
                                                            event::IoOperationCompleteCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoOperationCancelledCallback(event_callbacks,
                                                            event::IoOperationCancelledCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoAcquireLockCallback(event_callbacks,
                                                            event::IoAcquireLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoReleaseLockCallback(event_callbacks,
                                                            event::IoReleaseLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetIoTryLockCallback(event_callbacks,
                                                            event::IoTryLockCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetProgramBeginCallback(event_callbacks,
                                                            event::ProgramBeginCb);
    

    OTF2_GlobalEvtReaderCallbacks_SetProgramEndCallback(event_callbacks,
                                                            event::ProgramEndCb);
    

    OTF2_Reader_RegisterGlobalEvtCallbacks(m_reader.get(),
                                           m_global_event_reader.get(),
                                           event_callbacks,
                                           this);    
    
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