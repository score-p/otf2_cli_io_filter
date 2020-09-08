#include <local_callbacks.hpp>
#include <local_reader.hpp>

void
LocalReader::read_definitions(OTF2_Reader *reader, const std::vector<size_t> &locations)
{
    bool successful_open_def_files = OTF2_Reader_OpenDefFiles(reader) == OTF2_SUCCESS;

    OTF2_DefReaderCallbacks *def_callbacks = OTF2_DefReaderCallbacks_New();

    OTF2_DefReaderCallbacks_SetMappingTableCallback(def_callbacks, definition::LocalMappingTableCb);

    OTF2_DefReaderCallbacks_SetClockOffsetCallback(def_callbacks, definition::LocalClockOffsetCb);

    OTF2_DefReaderCallbacks_SetStringCallback(def_callbacks, definition::LocalStringCb);

    OTF2_DefReaderCallbacks_SetAttributeCallback(def_callbacks, definition::LocalAttributeCb);

    OTF2_DefReaderCallbacks_SetSystemTreeNodeCallback(def_callbacks, definition::LocalSystemTreeNodeCb);

    OTF2_DefReaderCallbacks_SetLocationGroupCallback(def_callbacks, definition::LocalLocationGroupCb);

    OTF2_DefReaderCallbacks_SetLocationCallback(def_callbacks, definition::LocalLocationCb);

    OTF2_DefReaderCallbacks_SetRegionCallback(def_callbacks, definition::LocalRegionCb);

    OTF2_DefReaderCallbacks_SetCallsiteCallback(def_callbacks, definition::LocalCallsiteCb);

    OTF2_DefReaderCallbacks_SetCallpathCallback(def_callbacks, definition::LocalCallpathCb);

    OTF2_DefReaderCallbacks_SetGroupCallback(def_callbacks, definition::LocalGroupCb);

    OTF2_DefReaderCallbacks_SetMetricMemberCallback(def_callbacks, definition::LocalMetricMemberCb);

    OTF2_DefReaderCallbacks_SetMetricClassCallback(def_callbacks, definition::LocalMetricClassCb);

    OTF2_DefReaderCallbacks_SetMetricInstanceCallback(def_callbacks, definition::LocalMetricInstanceCb);

    OTF2_DefReaderCallbacks_SetCommCallback(def_callbacks, definition::LocalCommCb);

    OTF2_DefReaderCallbacks_SetParameterCallback(def_callbacks, definition::LocalParameterCb);

    OTF2_DefReaderCallbacks_SetRmaWinCallback(def_callbacks, definition::LocalRmaWinCb);

    OTF2_DefReaderCallbacks_SetMetricClassRecorderCallback(def_callbacks, definition::LocalMetricClassRecorderCb);

    OTF2_DefReaderCallbacks_SetSystemTreeNodePropertyCallback(def_callbacks, definition::LocalSystemTreeNodePropertyCb);

    OTF2_DefReaderCallbacks_SetSystemTreeNodeDomainCallback(def_callbacks, definition::LocalSystemTreeNodeDomainCb);

    OTF2_DefReaderCallbacks_SetLocationGroupPropertyCallback(def_callbacks, definition::LocalLocationGroupPropertyCb);

    OTF2_DefReaderCallbacks_SetLocationPropertyCallback(def_callbacks, definition::LocalLocationPropertyCb);

    OTF2_DefReaderCallbacks_SetCartDimensionCallback(def_callbacks, definition::LocalCartDimensionCb);

    OTF2_DefReaderCallbacks_SetCartTopologyCallback(def_callbacks, definition::LocalCartTopologyCb);

    OTF2_DefReaderCallbacks_SetCartCoordinateCallback(def_callbacks, definition::LocalCartCoordinateCb);

    OTF2_DefReaderCallbacks_SetSourceCodeLocationCallback(def_callbacks, definition::LocalSourceCodeLocationCb);

    OTF2_DefReaderCallbacks_SetCallingContextCallback(def_callbacks, definition::LocalCallingContextCb);

    OTF2_DefReaderCallbacks_SetCallingContextPropertyCallback(def_callbacks, definition::LocalCallingContextPropertyCb);

    OTF2_DefReaderCallbacks_SetInterruptGeneratorCallback(def_callbacks, definition::LocalInterruptGeneratorCb);

    OTF2_DefReaderCallbacks_SetIoFilePropertyCallback(def_callbacks, definition::LocalIoFilePropertyCb);

    OTF2_DefReaderCallbacks_SetIoRegularFileCallback(def_callbacks, definition::LocalIoRegularFileCb);

    OTF2_DefReaderCallbacks_SetIoDirectoryCallback(def_callbacks, definition::LocalIoDirectoryCb);

    OTF2_DefReaderCallbacks_SetIoHandleCallback(def_callbacks, definition::LocalIoHandleCb);

    OTF2_DefReaderCallbacks_SetIoPreCreatedHandleStateCallback(def_callbacks,
                                                               definition::LocalIoPreCreatedHandleStateCb);

    OTF2_DefReaderCallbacks_SetCallpathParameterCallback(def_callbacks, definition::LocalCallpathParameterCb);

    for (auto location : locations)
    {
        if (successful_open_def_files)
        {
            OTF2_DefReader *def_reader = OTF2_Reader_GetDefReader(reader, location);
            OTF2_Reader_RegisterDefCallbacks(reader, def_reader, def_callbacks, this);
            if (def_reader)
            {
                uint64_t def_reads = 0;
                // FIXME Assume to save
                // state is not good but
                // put all in a pair
                // pointer is also not
                // great
                m_current_location = location;
                OTF2_Reader_ReadAllLocalDefinitions(reader, def_reader, &def_reads);
                OTF2_Reader_CloseDefReader(reader, def_reader);
            }
        }
        [[maybe_unused]] OTF2_EvtReader *evt_reader = OTF2_Reader_GetEvtReader(reader, location);
    }
    if (successful_open_def_files)
    {
        OTF2_Reader_CloseDefFiles(reader);
    }
}

void
LocalReader::read_events(OTF2_Reader *reader, const std::vector<size_t> &locations)
{
    OTF2_Reader_OpenEvtFiles(reader);

    OTF2_EvtReaderCallbacks *evt_callbacks = OTF2_EvtReaderCallbacks_New();

    OTF2_EvtReaderCallbacks_SetBufferFlushCallback(evt_callbacks, event::LocalBufferFlushCb);

    OTF2_EvtReaderCallbacks_SetMeasurementOnOffCallback(evt_callbacks, event::LocalMeasurementOnOffCb);

    OTF2_EvtReaderCallbacks_SetEnterCallback(evt_callbacks, event::LocalEnterCb);

    OTF2_EvtReaderCallbacks_SetLeaveCallback(evt_callbacks, event::LocalLeaveCb);

    OTF2_EvtReaderCallbacks_SetMpiSendCallback(evt_callbacks, event::LocalMpiSendCb);

    OTF2_EvtReaderCallbacks_SetMpiIsendCallback(evt_callbacks, event::LocalMpiIsendCb);

    OTF2_EvtReaderCallbacks_SetMpiIsendCompleteCallback(evt_callbacks, event::LocalMpiIsendCompleteCb);

    OTF2_EvtReaderCallbacks_SetMpiIrecvRequestCallback(evt_callbacks, event::LocalMpiIrecvRequestCb);

    OTF2_EvtReaderCallbacks_SetMpiRecvCallback(evt_callbacks, event::LocalMpiRecvCb);

    OTF2_EvtReaderCallbacks_SetMpiIrecvCallback(evt_callbacks, event::LocalMpiIrecvCb);

    OTF2_EvtReaderCallbacks_SetMpiRequestTestCallback(evt_callbacks, event::LocalMpiRequestTestCb);

    OTF2_EvtReaderCallbacks_SetMpiRequestCancelledCallback(evt_callbacks, event::LocalMpiRequestCancelledCb);

    OTF2_EvtReaderCallbacks_SetMpiCollectiveBeginCallback(evt_callbacks, event::LocalMpiCollectiveBeginCb);

    OTF2_EvtReaderCallbacks_SetMpiCollectiveEndCallback(evt_callbacks, event::LocalMpiCollectiveEndCb);

    OTF2_EvtReaderCallbacks_SetOmpForkCallback(evt_callbacks, event::LocalOmpForkCb);

    OTF2_EvtReaderCallbacks_SetOmpJoinCallback(evt_callbacks, event::LocalOmpJoinCb);

    OTF2_EvtReaderCallbacks_SetOmpAcquireLockCallback(evt_callbacks, event::LocalOmpAcquireLockCb);

    OTF2_EvtReaderCallbacks_SetOmpReleaseLockCallback(evt_callbacks, event::LocalOmpReleaseLockCb);

    OTF2_EvtReaderCallbacks_SetOmpTaskCreateCallback(evt_callbacks, event::LocalOmpTaskCreateCb);

    OTF2_EvtReaderCallbacks_SetOmpTaskSwitchCallback(evt_callbacks, event::LocalOmpTaskSwitchCb);

    OTF2_EvtReaderCallbacks_SetOmpTaskCompleteCallback(evt_callbacks, event::LocalOmpTaskCompleteCb);

    OTF2_EvtReaderCallbacks_SetMetricCallback(evt_callbacks, event::LocalMetricCb);

    OTF2_EvtReaderCallbacks_SetParameterStringCallback(evt_callbacks, event::LocalParameterStringCb);

    OTF2_EvtReaderCallbacks_SetParameterIntCallback(evt_callbacks, event::LocalParameterIntCb);

    OTF2_EvtReaderCallbacks_SetParameterUnsignedIntCallback(evt_callbacks, event::LocalParameterUnsignedIntCb);

    OTF2_EvtReaderCallbacks_SetRmaWinCreateCallback(evt_callbacks, event::LocalRmaWinCreateCb);

    OTF2_EvtReaderCallbacks_SetRmaWinDestroyCallback(evt_callbacks, event::LocalRmaWinDestroyCb);

    OTF2_EvtReaderCallbacks_SetRmaCollectiveBeginCallback(evt_callbacks, event::LocalRmaCollectiveBeginCb);

    OTF2_EvtReaderCallbacks_SetRmaCollectiveEndCallback(evt_callbacks, event::LocalRmaCollectiveEndCb);

    OTF2_EvtReaderCallbacks_SetRmaGroupSyncCallback(evt_callbacks, event::LocalRmaGroupSyncCb);

    OTF2_EvtReaderCallbacks_SetRmaRequestLockCallback(evt_callbacks, event::LocalRmaRequestLockCb);

    OTF2_EvtReaderCallbacks_SetRmaAcquireLockCallback(evt_callbacks, event::LocalRmaAcquireLockCb);

    OTF2_EvtReaderCallbacks_SetRmaTryLockCallback(evt_callbacks, event::LocalRmaTryLockCb);

    OTF2_EvtReaderCallbacks_SetRmaReleaseLockCallback(evt_callbacks, event::LocalRmaReleaseLockCb);

    OTF2_EvtReaderCallbacks_SetRmaSyncCallback(evt_callbacks, event::LocalRmaSyncCb);

    OTF2_EvtReaderCallbacks_SetRmaWaitChangeCallback(evt_callbacks, event::LocalRmaWaitChangeCb);

    OTF2_EvtReaderCallbacks_SetRmaPutCallback(evt_callbacks, event::LocalRmaPutCb);

    OTF2_EvtReaderCallbacks_SetRmaGetCallback(evt_callbacks, event::LocalRmaGetCb);

    OTF2_EvtReaderCallbacks_SetRmaAtomicCallback(evt_callbacks, event::LocalRmaAtomicCb);

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteBlockingCallback(evt_callbacks, event::LocalRmaOpCompleteBlockingCb);

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteNonBlockingCallback(evt_callbacks, event::LocalRmaOpCompleteNonBlockingCb);

    OTF2_EvtReaderCallbacks_SetRmaOpTestCallback(evt_callbacks, event::LocalRmaOpTestCb);

    OTF2_EvtReaderCallbacks_SetRmaOpCompleteRemoteCallback(evt_callbacks, event::LocalRmaOpCompleteRemoteCb);

    OTF2_EvtReaderCallbacks_SetThreadForkCallback(evt_callbacks, event::LocalThreadForkCb);

    OTF2_EvtReaderCallbacks_SetThreadJoinCallback(evt_callbacks, event::LocalThreadJoinCb);

    OTF2_EvtReaderCallbacks_SetThreadTeamBeginCallback(evt_callbacks, event::LocalThreadTeamBeginCb);

    OTF2_EvtReaderCallbacks_SetThreadTeamEndCallback(evt_callbacks, event::LocalThreadTeamEndCb);

    OTF2_EvtReaderCallbacks_SetThreadAcquireLockCallback(evt_callbacks, event::LocalThreadAcquireLockCb);

    OTF2_EvtReaderCallbacks_SetThreadReleaseLockCallback(evt_callbacks, event::LocalThreadReleaseLockCb);

    OTF2_EvtReaderCallbacks_SetThreadTaskCreateCallback(evt_callbacks, event::LocalThreadTaskCreateCb);

    OTF2_EvtReaderCallbacks_SetThreadTaskSwitchCallback(evt_callbacks, event::LocalThreadTaskSwitchCb);

    OTF2_EvtReaderCallbacks_SetThreadTaskCompleteCallback(evt_callbacks, event::LocalThreadTaskCompleteCb);

    OTF2_EvtReaderCallbacks_SetThreadCreateCallback(evt_callbacks, event::LocalThreadCreateCb);

    OTF2_EvtReaderCallbacks_SetThreadBeginCallback(evt_callbacks, event::LocalThreadBeginCb);

    OTF2_EvtReaderCallbacks_SetThreadWaitCallback(evt_callbacks, event::LocalThreadWaitCb);

    OTF2_EvtReaderCallbacks_SetThreadEndCallback(evt_callbacks, event::LocalThreadEndCb);

    OTF2_EvtReaderCallbacks_SetCallingContextEnterCallback(evt_callbacks, event::LocalCallingContextEnterCb);

    OTF2_EvtReaderCallbacks_SetCallingContextLeaveCallback(evt_callbacks, event::LocalCallingContextLeaveCb);

    OTF2_EvtReaderCallbacks_SetCallingContextSampleCallback(evt_callbacks, event::LocalCallingContextSampleCb);

    OTF2_EvtReaderCallbacks_SetIoCreateHandleCallback(evt_callbacks, event::LocalIoCreateHandleCb);

    OTF2_EvtReaderCallbacks_SetIoDestroyHandleCallback(evt_callbacks, event::LocalIoDestroyHandleCb);

    OTF2_EvtReaderCallbacks_SetIoDuplicateHandleCallback(evt_callbacks, event::LocalIoDuplicateHandleCb);

    OTF2_EvtReaderCallbacks_SetIoSeekCallback(evt_callbacks, event::LocalIoSeekCb);

    OTF2_EvtReaderCallbacks_SetIoChangeStatusFlagsCallback(evt_callbacks, event::LocalIoChangeStatusFlagsCb);

    OTF2_EvtReaderCallbacks_SetIoDeleteFileCallback(evt_callbacks, event::LocalIoDeleteFileCb);

    OTF2_EvtReaderCallbacks_SetIoOperationBeginCallback(evt_callbacks, event::LocalIoOperationBeginCb);

    OTF2_EvtReaderCallbacks_SetIoOperationTestCallback(evt_callbacks, event::LocalIoOperationTestCb);

    OTF2_EvtReaderCallbacks_SetIoOperationIssuedCallback(evt_callbacks, event::LocalIoOperationIssuedCb);

    OTF2_EvtReaderCallbacks_SetIoOperationCompleteCallback(evt_callbacks, event::LocalIoOperationCompleteCb);

    OTF2_EvtReaderCallbacks_SetIoOperationCancelledCallback(evt_callbacks, event::LocalIoOperationCancelledCb);

    OTF2_EvtReaderCallbacks_SetIoAcquireLockCallback(evt_callbacks, event::LocalIoAcquireLockCb);

    OTF2_EvtReaderCallbacks_SetIoReleaseLockCallback(evt_callbacks, event::LocalIoReleaseLockCb);

    OTF2_EvtReaderCallbacks_SetIoTryLockCallback(evt_callbacks, event::LocalIoTryLockCb);

    OTF2_EvtReaderCallbacks_SetProgramBeginCallback(evt_callbacks, event::LocalProgramBeginCb);

    OTF2_EvtReaderCallbacks_SetProgramEndCallback(evt_callbacks, event::LocalProgramEndCb);

    for (auto location : locations)
    {
        OTF2_EvtReader *evt_reader = OTF2_Reader_GetEvtReader(reader, location);
        OTF2_Reader_RegisterEvtCallbacks(reader, evt_reader, evt_callbacks, this);
        if (evt_reader)
        {
            uint64_t events_read;
            OTF2_Reader_ReadAllLocalEvents(reader, evt_reader, &events_read);

            OTF2_Reader_CloseEvtReader(reader, evt_reader);
        }
    }
    OTF2_EvtReaderCallbacks_Delete(evt_callbacks);
    OTF2_Reader_CloseEvtFiles(reader);
}

void
LocalReader::operator()(OTF2_Reader *reader, std::vector<size_t> locations)
{
    uint64_t number_of_locations_to_read = 0;
    for (auto location : locations)
    {
        number_of_locations_to_read++;
        OTF2_Reader_SelectLocation(reader, location);
    }

    if (number_of_locations_to_read > 0)
    {
        read_events(reader, locations);
    }
}