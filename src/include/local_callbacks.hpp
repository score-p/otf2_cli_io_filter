#ifndef EVENT_CALLBACKS_HPP
#define EVENT_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace event
{
    
    OTF2_CallbackCode
    BufferFlushCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_TimeStamp stopTime);

    
    OTF2_CallbackCode
    MeasurementOnOffCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_MeasurementMode measurementMode);

    
    OTF2_CallbackCode
    EnterCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RegionRef region);

    
    OTF2_CallbackCode
    LeaveCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RegionRef region);

    
    OTF2_CallbackCode
    MpiSendCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t receiver,
OTF2_CommRef communicator,
uint32_t msgTag,
uint64_t msgLength);

    
    OTF2_CallbackCode
    MpiIsendCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t receiver,
OTF2_CommRef communicator,
uint32_t msgTag,
uint64_t msgLength,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiIsendCompleteCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiIrecvRequestCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiRecvCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t sender,
OTF2_CommRef communicator,
uint32_t msgTag,
uint64_t msgLength);

    
    OTF2_CallbackCode
    MpiIrecvCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t sender,
OTF2_CommRef communicator,
uint32_t msgTag,
uint64_t msgLength,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiRequestTestCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiRequestCancelledCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t requestID);

    
    OTF2_CallbackCode
    MpiCollectiveBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes);

    
    OTF2_CallbackCode
    MpiCollectiveEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CollectiveOp collectiveOp,
OTF2_CommRef communicator,
uint32_t root,
uint64_t sizeSent,
uint64_t sizeReceived);

    
    OTF2_CallbackCode
    OmpForkCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t numberOfRequestedThreads);

    
    OTF2_CallbackCode
    OmpJoinCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes);

    
    OTF2_CallbackCode
    OmpAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t lockID,
uint32_t acquisitionOrder);

    
    OTF2_CallbackCode
    OmpReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint32_t lockID,
uint32_t acquisitionOrder);

    
    OTF2_CallbackCode
    OmpTaskCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t taskID);

    
    OTF2_CallbackCode
    OmpTaskSwitchCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t taskID);

    
    OTF2_CallbackCode
    OmpTaskCompleteCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
uint64_t taskID);

    
    OTF2_CallbackCode
    MetricCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_MetricRef metric,
uint8_t numberOfMetrics,
const OTF2_Type* typeIDs,
const OTF2_MetricValue* metricValues);

    
    OTF2_CallbackCode
    ParameterStringCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_ParameterRef parameter,
OTF2_StringRef string);

    
    OTF2_CallbackCode
    ParameterIntCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_ParameterRef parameter,
int64_t value);

    
    OTF2_CallbackCode
    ParameterUnsignedIntCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_ParameterRef parameter,
uint64_t value);

    
    OTF2_CallbackCode
    RmaWinCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win);

    
    OTF2_CallbackCode
    RmaWinDestroyCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win);

    
    OTF2_CallbackCode
    RmaCollectiveBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes);

    
    OTF2_CallbackCode
    RmaCollectiveEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CollectiveOp collectiveOp,
OTF2_RmaSyncLevel syncLevel,
OTF2_RmaWinRef win,
uint32_t root,
uint64_t bytesSent,
uint64_t bytesReceived);

    
    OTF2_CallbackCode
    RmaGroupSyncCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaSyncLevel syncLevel,
OTF2_RmaWinRef win,
OTF2_GroupRef group);

    
    OTF2_CallbackCode
    RmaRequestLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t lockId,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    RmaAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t lockId,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    RmaTryLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t lockId,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    RmaReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t lockId);

    
    OTF2_CallbackCode
    RmaSyncCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
OTF2_RmaSyncType syncType);

    
    OTF2_CallbackCode
    RmaWaitChangeCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win);

    
    OTF2_CallbackCode
    RmaPutCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t bytes,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaGetCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
uint64_t bytes,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaAtomicCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint32_t remote,
OTF2_RmaAtomicType type,
uint64_t bytesSent,
uint64_t bytesReceived,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaOpCompleteBlockingCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaOpCompleteNonBlockingCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaOpTestCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint64_t matchingId);

    
    OTF2_CallbackCode
    RmaOpCompleteRemoteCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_RmaWinRef win,
uint64_t matchingId);

    
    OTF2_CallbackCode
    ThreadForkCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_Paradigm model,
uint32_t numberOfRequestedThreads);

    
    OTF2_CallbackCode
    ThreadJoinCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_Paradigm model);

    
    OTF2_CallbackCode
    ThreadTeamBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadTeam);

    
    OTF2_CallbackCode
    ThreadTeamEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadTeam);

    
    OTF2_CallbackCode
    ThreadAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_Paradigm model,
uint32_t lockID,
uint32_t acquisitionOrder);

    
    OTF2_CallbackCode
    ThreadReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_Paradigm model,
uint32_t lockID,
uint32_t acquisitionOrder);

    
    OTF2_CallbackCode
    ThreadTaskCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadTeam,
uint32_t creatingThread,
uint32_t generationNumber);

    
    OTF2_CallbackCode
    ThreadTaskSwitchCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadTeam,
uint32_t creatingThread,
uint32_t generationNumber);

    
    OTF2_CallbackCode
    ThreadTaskCompleteCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadTeam,
uint32_t creatingThread,
uint32_t generationNumber);

    
    OTF2_CallbackCode
    ThreadCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadContingent,
uint64_t sequenceCount);

    
    OTF2_CallbackCode
    ThreadBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadContingent,
uint64_t sequenceCount);

    
    OTF2_CallbackCode
    ThreadWaitCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadContingent,
uint64_t sequenceCount);

    
    OTF2_CallbackCode
    ThreadEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CommRef threadContingent,
uint64_t sequenceCount);

    
    OTF2_CallbackCode
    CallingContextEnterCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CallingContextRef callingContext,
uint32_t unwindDistance);

    
    OTF2_CallbackCode
    CallingContextLeaveCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CallingContextRef callingContext);

    
    OTF2_CallbackCode
    CallingContextSampleCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_CallingContextRef callingContext,
uint32_t unwindDistance,
OTF2_InterruptGeneratorRef interruptGenerator);

    
    OTF2_CallbackCode
    IoCreateHandleCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_IoAccessMode mode,
OTF2_IoCreationFlag creationFlags,
OTF2_IoStatusFlag statusFlags);

    
    OTF2_CallbackCode
    IoDestroyHandleCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle);

    
    OTF2_CallbackCode
    IoDuplicateHandleCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef oldHandle,
OTF2_IoHandleRef newHandle,
OTF2_IoStatusFlag statusFlags);

    
    OTF2_CallbackCode
    IoSeekCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
int64_t offsetRequest,
OTF2_IoSeekOption whence,
uint64_t offsetResult);

    
    OTF2_CallbackCode
    IoChangeStatusFlagsCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_IoStatusFlag statusFlags);

    
    OTF2_CallbackCode
    IoDeleteFileCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoParadigmRef ioParadigm,
OTF2_IoFileRef file);

    
    OTF2_CallbackCode
    IoOperationBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_IoOperationMode mode,
OTF2_IoOperationFlag operationFlags,
uint64_t bytesRequest,
uint64_t matchingId);

    
    OTF2_CallbackCode
    IoOperationTestCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
uint64_t matchingId);

    
    OTF2_CallbackCode
    IoOperationIssuedCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
uint64_t matchingId);

    
    OTF2_CallbackCode
    IoOperationCompleteCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
uint64_t bytesResult,
uint64_t matchingId);

    
    OTF2_CallbackCode
    IoOperationCancelledCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
uint64_t matchingId);

    
    OTF2_CallbackCode
    IoAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    IoReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    IoTryLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_IoHandleRef handle,
OTF2_LockType lockType);

    
    OTF2_CallbackCode
    ProgramBeginCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
OTF2_StringRef programName,
uint32_t numberOfArguments,
const OTF2_StringRef* programArguments);

    
    OTF2_CallbackCode
    ProgramEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes,
int64_t exitStatus);

}

#endif /* EVENT_CALLBACKS_HPP */