#include <iostream>
#include <local_reader.hpp>
#include <local_callbacks.hpp>
#include <definition_callbacks.hpp>

LocalReader::~LocalReader()
{
    if(nevents > 0)
    {
        std::cout << "Read " << nevents << " events.\n";
        std::cout << "Read " << nstring_defs << " string defs.\n";
    }
}

void
LocalReader::read_events(OTF2_Reader* reader, const std::vector<size_t> & locations)
{
    OTF2_Reader_OpenEvtFiles( reader );

    OTF2_EvtReaderCallbacks* evt_callbacks = OTF2_EvtReaderCallbacks_New();


    OTF2_EvtReaderCallbacks_SetBufferFlushCallback(evt_callbacks,
                                                      event::BufferFlushCb);
    

    OTF2_EvtReaderCallbacks_SetMeasurementOnOffCallback(evt_callbacks,
                                                      event::MeasurementOnOffCb);
    

    OTF2_EvtReaderCallbacks_SetEnterCallback(evt_callbacks,
                                                      event::EnterCb);
    

    OTF2_EvtReaderCallbacks_SetLeaveCallback(evt_callbacks,
                                                      event::LeaveCb);
    

    OTF2_EvtReaderCallbacks_SetMpiSendCallback(evt_callbacks,
                                                      event::MpiSendCb);
    

    OTF2_EvtReaderCallbacks_SetMpiIsendCallback(evt_callbacks,
                                                      event::MpiIsendCb);
    

    OTF2_EvtReaderCallbacks_SetMpiIsendCompleteCallback(evt_callbacks,
                                                      event::MpiIsendCompleteCb);
    

    OTF2_EvtReaderCallbacks_SetMpiIrecvRequestCallback(evt_callbacks,
                                                      event::MpiIrecvRequestCb);
    

    OTF2_EvtReaderCallbacks_SetMpiRecvCallback(evt_callbacks,
                                                      event::MpiRecvCb);
    

    OTF2_EvtReaderCallbacks_SetMpiIrecvCallback(evt_callbacks,
                                                      event::MpiIrecvCb);
    

    OTF2_EvtReaderCallbacks_SetMpiRequestTestCallback(evt_callbacks,
                                                      event::MpiRequestTestCb);
    

    OTF2_EvtReaderCallbacks_SetMpiRequestCancelledCallback(evt_callbacks,
                                                      event::MpiRequestCancelledCb);
    

    OTF2_EvtReaderCallbacks_SetMpiCollectiveBeginCallback(evt_callbacks,
                                                      event::MpiCollectiveBeginCb);
    

    OTF2_EvtReaderCallbacks_SetMpiCollectiveEndCallback(evt_callbacks,
                                                      event::MpiCollectiveEndCb);
    

    OTF2_EvtReaderCallbacks_SetOmpForkCallback(evt_callbacks,
                                                      event::OmpForkCb);
    

    OTF2_EvtReaderCallbacks_SetOmpJoinCallback(evt_callbacks,
                                                      event::OmpJoinCb);
    

    OTF2_EvtReaderCallbacks_SetOmpAcquireLockCallback(evt_callbacks,
                                                      event::OmpAcquireLockCb);
    

    OTF2_EvtReaderCallbacks_SetOmpReleaseLockCallback(evt_callbacks,
                                                      event::OmpReleaseLockCb);
    

    OTF2_EvtReaderCallbacks_SetOmpTaskCreateCallback(evt_callbacks,
                                                      event::OmpTaskCreateCb);
    

    OTF2_EvtReaderCallbacks_SetOmpTaskSwitchCallback(evt_callbacks,
                                                      event::OmpTaskSwitchCb);
    

    OTF2_EvtReaderCallbacks_SetOmpTaskCompleteCallback(evt_callbacks,
                                                      event::OmpTaskCompleteCb);
    

    OTF2_EvtReaderCallbacks_SetMetricCallback(evt_callbacks,
                                                      event::MetricCb);
    

    OTF2_EvtReaderCallbacks_SetParameterStringCallback(evt_callbacks,
                                                      event::ParameterStringCb);
    

    OTF2_EvtReaderCallbacks_SetParameterIntCallback(evt_callbacks,
                                                      event::ParameterIntCb);
    

    OTF2_EvtReaderCallbacks_SetParameterUnsignedIntCallback(evt_callbacks,
                                                      event::ParameterUnsignedIntCb);
    

    OTF2_EvtReaderCallbacks_SetRmaWinCreateCallback(evt_callbacks,
                                                      event::RmaWinCreateCb);
    

    OTF2_EvtReaderCallbacks_SetRmaWinDestroyCallback(evt_callbacks,
                                                      event::RmaWinDestroyCb);
    

    OTF2_EvtReaderCallbacks_SetRmaCollectiveBeginCallback(evt_callbacks,
                                                      event::RmaCollectiveBeginCb);
    

    OTF2_EvtReaderCallbacks_SetRmaCollectiveEndCallback(evt_callbacks,
                                                      event::RmaCollectiveEndCb);
    

    OTF2_EvtReaderCallbacks_SetRmaGroupSyncCallback(evt_callbacks,
                                                      event::RmaGroupSyncCb);
    

    OTF2_EvtReaderCallbacks_SetRmaRequestLockCallback(evt_callbacks,
                                                      event::RmaRequestLockCb);
    

    OTF2_EvtReaderCallbacks_SetRmaAcquireLockCallback(evt_callbacks,
                                                      event::RmaAcquireLockCb);
    

    OTF2_EvtReaderCallbacks_SetRmaTryLockCallback(evt_callbacks,
                                                      event::RmaTryLockCb);
    

    OTF2_EvtReaderCallbacks_SetRmaReleaseLockCallback(evt_callbacks,
                                                      event::RmaReleaseLockCb);
    

    OTF2_EvtReaderCallbacks_SetRmaSyncCallback(evt_callbacks,
                                                      event::RmaSyncCb);
    

    OTF2_EvtReaderCallbacks_SetRmaWaitChangeCallback(evt_callbacks,
                                                      event::RmaWaitChangeCb);
    

    OTF2_EvtReaderCallbacks_SetRmaPutCallback(evt_callbacks,
                                                      event::RmaPutCb);
    

    OTF2_EvtReaderCallbacks_SetRmaGetCallback(evt_callbacks,
                                                      event::RmaGetCb);
    

    OTF2_EvtReaderCallbacks_SetRmaAtomicCallback(evt_callbacks,
                                                      event::RmaAtomicCb);
    

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteBlockingCallback(evt_callbacks,
                                                      event::RmaOpCompleteBlockingCb);
    

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteNonBlockingCallback(evt_callbacks,
                                                      event::RmaOpCompleteNonBlockingCb);
    

    OTF2_EvtReaderCallbacks_SetRmaOpTestCallback(evt_callbacks,
                                                      event::RmaOpTestCb);
    

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteRemoteCallback(evt_callbacks,
                                                      event::RmaOpCompleteRemoteCb);
    

    OTF2_EvtReaderCallbacks_SetThreadForkCallback(evt_callbacks,
                                                      event::ThreadForkCb);
    

    OTF2_EvtReaderCallbacks_SetThreadJoinCallback(evt_callbacks,
                                                      event::ThreadJoinCb);
    

    OTF2_EvtReaderCallbacks_SetThreadTeamBeginCallback(evt_callbacks,
                                                      event::ThreadTeamBeginCb);
    

    OTF2_EvtReaderCallbacks_SetThreadTeamEndCallback(evt_callbacks,
                                                      event::ThreadTeamEndCb);
    

    OTF2_EvtReaderCallbacks_SetThreadAcquireLockCallback(evt_callbacks,
                                                      event::ThreadAcquireLockCb);
    

    OTF2_EvtReaderCallbacks_SetThreadReleaseLockCallback(evt_callbacks,
                                                      event::ThreadReleaseLockCb);
    

    OTF2_EvtReaderCallbacks_SetThreadTaskCreateCallback(evt_callbacks,
                                                      event::ThreadTaskCreateCb);
    

    OTF2_EvtReaderCallbacks_SetThreadTaskSwitchCallback(evt_callbacks,
                                                      event::ThreadTaskSwitchCb);
    

    OTF2_EvtReaderCallbacks_SetThreadTaskCompleteCallback(evt_callbacks,
                                                      event::ThreadTaskCompleteCb);
    

    OTF2_EvtReaderCallbacks_SetThreadCreateCallback(evt_callbacks,
                                                      event::ThreadCreateCb);
    

    OTF2_EvtReaderCallbacks_SetThreadBeginCallback(evt_callbacks,
                                                      event::ThreadBeginCb);
    

    OTF2_EvtReaderCallbacks_SetThreadWaitCallback(evt_callbacks,
                                                      event::ThreadWaitCb);
    

    OTF2_EvtReaderCallbacks_SetThreadEndCallback(evt_callbacks,
                                                      event::ThreadEndCb);
    

    OTF2_EvtReaderCallbacks_SetCallingContextEnterCallback(evt_callbacks,
                                                      event::CallingContextEnterCb);
    

    OTF2_EvtReaderCallbacks_SetCallingContextLeaveCallback(evt_callbacks,
                                                      event::CallingContextLeaveCb);
    

    OTF2_EvtReaderCallbacks_SetCallingContextSampleCallback(evt_callbacks,
                                                      event::CallingContextSampleCb);
    

    OTF2_EvtReaderCallbacks_SetIoCreateHandleCallback(evt_callbacks,
                                                      event::IoCreateHandleCb);
    

    OTF2_EvtReaderCallbacks_SetIoDestroyHandleCallback(evt_callbacks,
                                                      event::IoDestroyHandleCb);
    

    OTF2_EvtReaderCallbacks_SetIoDuplicateHandleCallback(evt_callbacks,
                                                      event::IoDuplicateHandleCb);
    

    OTF2_EvtReaderCallbacks_SetIoSeekCallback(evt_callbacks,
                                                      event::IoSeekCb);
    

    OTF2_EvtReaderCallbacks_SetIoChangeStatusFlagsCallback(evt_callbacks,
                                                      event::IoChangeStatusFlagsCb);
    

    OTF2_EvtReaderCallbacks_SetIoDeleteFileCallback(evt_callbacks,
                                                      event::IoDeleteFileCb);
    

    OTF2_EvtReaderCallbacks_SetIoOperationBeginCallback(evt_callbacks,
                                                      event::IoOperationBeginCb);
    

    OTF2_EvtReaderCallbacks_SetIoOperationTestCallback(evt_callbacks,
                                                      event::IoOperationTestCb);
    

    OTF2_EvtReaderCallbacks_SetIoOperationIssuedCallback(evt_callbacks,
                                                      event::IoOperationIssuedCb);
    

    OTF2_EvtReaderCallbacks_SetIoOperationCompleteCallback(evt_callbacks,
                                                      event::IoOperationCompleteCb);
    

    OTF2_EvtReaderCallbacks_SetIoOperationCancelledCallback(evt_callbacks,
                                                      event::IoOperationCancelledCb);
    

    OTF2_EvtReaderCallbacks_SetIoAcquireLockCallback(evt_callbacks,
                                                      event::IoAcquireLockCb);
    

    OTF2_EvtReaderCallbacks_SetIoReleaseLockCallback(evt_callbacks,
                                                      event::IoReleaseLockCb);
    

    OTF2_EvtReaderCallbacks_SetIoTryLockCallback(evt_callbacks,
                                                      event::IoTryLockCb);
    

    OTF2_EvtReaderCallbacks_SetProgramBeginCallback(evt_callbacks,
                                                      event::ProgramBeginCb);
    

    OTF2_EvtReaderCallbacks_SetProgramEndCallback(evt_callbacks,
                                                      event::ProgramEndCb);
    

    for (auto location: locations)
    {
        OTF2_EvtReader *  evt_reader = OTF2_Reader_GetEvtReader( reader, location);

        if(evt_reader)
        {
            OTF2_Reader_RegisterEvtCallbacks(reader,
                                            evt_reader,
                                            evt_callbacks,
                                            this);
            uint64_t events_read;
            OTF2_Reader_ReadAllLocalEvents(reader,
                                            evt_reader,
                                            &events_read);
            std::cout << "Read " << events_read << '\n';
            OTF2_Reader_CloseEvtReader(reader,
                                        evt_reader);
        }
    }
    OTF2_EvtReaderCallbacks_Delete( evt_callbacks );
    OTF2_Reader_CloseEvtFiles( reader );
}

void
LocalReader::operator() (OTF2_Reader* reader, std::vector<size_t> locations)
{
    uint64_t number_of_locations_to_read = 0;
    for (auto location: locations)
    {
        number_of_locations_to_read++;
        OTF2_Reader_SelectLocation( reader, location );
    }

    if ( number_of_locations_to_read > 0 )
    {
        read_events(reader, locations);
    }
}