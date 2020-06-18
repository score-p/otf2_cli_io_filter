#include "trace_reader.hpp"

namespace event {

OTF2_CallbackCode BufferFlushCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_TimeStamp stopTime) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeBufferFlushEvent(location,
                                          time,
                                          attributes,
stopTime);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MeasurementOnOffCb(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     uint64_t eventPosition, void *userData,
                                     OTF2_AttributeList *attributes,
                                     OTF2_MeasurementMode measurementMode) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMeasurementOnOffEvent(location,
                                          time,
                                          attributes,
measurementMode);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode EnterCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                          uint64_t eventPosition, void *userData,
                          OTF2_AttributeList *attributes,
                          OTF2_RegionRef region) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeEnterEvent(location,
                                          time,
                                          attributes,
region);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LeaveCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                          uint64_t eventPosition, void *userData,
                          OTF2_AttributeList *attributes,
                          OTF2_RegionRef region) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeLeaveEvent(location,
                                          time,
                                          attributes,
region);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiSendCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes, uint32_t receiver,
                            OTF2_CommRef communicator, uint32_t msgTag,
                            uint64_t msgLength) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiSendEvent(location,
                                          time,
                                          attributes,
receiver,
communicator,
msgTag,
msgLength);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiIsendCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                             uint64_t eventPosition, void *userData,
                             OTF2_AttributeList *attributes, uint32_t receiver,
                             OTF2_CommRef communicator, uint32_t msgTag,
                             uint64_t msgLength, uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiIsendEvent(location,
                                          time,
                                          attributes,
receiver,
communicator,
msgTag,
msgLength,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiIsendCompleteCb(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     uint64_t eventPosition, void *userData,
                                     OTF2_AttributeList *attributes,
                                     uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiIsendCompleteEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiIrecvRequestCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiIrecvRequestEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiRecvCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes, uint32_t sender,
                            OTF2_CommRef communicator, uint32_t msgTag,
                            uint64_t msgLength) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiRecvEvent(location,
                                          time,
                                          attributes,
sender,
communicator,
msgTag,
msgLength);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiIrecvCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                             uint64_t eventPosition, void *userData,
                             OTF2_AttributeList *attributes, uint32_t sender,
                             OTF2_CommRef communicator, uint32_t msgTag,
                             uint64_t msgLength, uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiIrecvEvent(location,
                                          time,
                                          attributes,
sender,
communicator,
msgTag,
msgLength,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiRequestTestCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiRequestTestEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiRequestCancelledCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        uint64_t requestID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiRequestCancelledEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiCollectiveBeginCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiCollectiveBeginEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MpiCollectiveEndCb(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     uint64_t eventPosition, void *userData,
                                     OTF2_AttributeList *attributes,
                                     OTF2_CollectiveOp collectiveOp,
                                     OTF2_CommRef communicator, uint32_t root,
                                     uint64_t sizeSent, uint64_t sizeReceived) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMpiCollectiveEndEvent(location,
                                          time,
                                          attributes,
collectiveOp,
communicator,
root,
sizeSent,
sizeReceived);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpForkCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes,
                            uint32_t numberOfRequestedThreads) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpForkEvent(location,
                                          time,
                                          attributes,
numberOfRequestedThreads);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpJoinCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpJoinEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpAcquireLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   uint32_t lockID, uint32_t acquisitionOrder) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpAcquireLockEvent(location,
                                          time,
                                          attributes,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpReleaseLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   uint32_t lockID, uint32_t acquisitionOrder) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpReleaseLockEvent(location,
                                          time,
                                          attributes,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpTaskCreateCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  uint64_t taskID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpTaskCreateEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpTaskSwitchCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  uint64_t taskID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpTaskSwitchEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode OmpTaskCompleteCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    uint64_t taskID) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeOmpTaskCompleteEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode MetricCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes,
                           OTF2_MetricRef metric, uint8_t numberOfMetrics,
                           const OTF2_Type *typeIDs,
                           const OTF2_MetricValue *metricValues) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeMetricEvent(location,
                                          time,
                                          attributes,
metric,
numberOfMetrics,
typeIDs,
metricValues);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ParameterStringCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_ParameterRef parameter,
                                    OTF2_StringRef string) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeParameterStringEvent(location,
                                          time,
                                          attributes,
parameter,
string);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ParameterIntCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_ParameterRef parameter, int64_t value) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeParameterIntEvent(location,
                                          time,
                                          attributes,
parameter,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ParameterUnsignedIntCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_ParameterRef parameter,
                                         uint64_t value) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeParameterUnsignedIntEvent(location,
                                          time,
                                          attributes,
parameter,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaWinCreateCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RmaWinRef win) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaWinCreateEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaWinDestroyCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaWinDestroyEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaCollectiveBeginCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaCollectiveBeginEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
RmaCollectiveEndCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                   uint64_t eventPosition, void *userData,
                   OTF2_AttributeList *attributes,
                   OTF2_CollectiveOp collectiveOp, OTF2_RmaSyncLevel syncLevel,
                   OTF2_RmaWinRef win, uint32_t root, uint64_t bytesSent,
                   uint64_t bytesReceived) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaCollectiveEndEvent(location,
                                          time,
                                          attributes,
collectiveOp,
syncLevel,
win,
root,
bytesSent,
bytesReceived);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaGroupSyncCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RmaSyncLevel syncLevel,
                                 OTF2_RmaWinRef win, OTF2_GroupRef group) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaGroupSyncEvent(location,
                                          time,
                                          attributes,
syncLevel,
win,
group);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaRequestLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaRequestLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaAcquireLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaAcquireLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaTryLockCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_RmaWinRef win, uint32_t remote,
                               uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaTryLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaReleaseLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   uint64_t lockId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaReleaseLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaSyncCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                            uint32_t remote, OTF2_RmaSyncType syncType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaSyncEvent(location,
                                          time,
                                          attributes,
win,
remote,
syncType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaWaitChangeCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaWaitChangeEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaPutCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                           uint32_t remote, uint64_t bytes,
                           uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaPutEvent(location,
                                          time,
                                          attributes,
win,
remote,
bytes,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaGetCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                           uint32_t remote, uint64_t bytes,
                           uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaGetEvent(location,
                                          time,
                                          attributes,
win,
remote,
bytes,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaAtomicCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                              uint64_t eventPosition, void *userData,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef win, uint32_t remote,
                              OTF2_RmaAtomicType type, uint64_t bytesSent,
                              uint64_t bytesReceived, uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaAtomicEvent(location,
                                          time,
                                          attributes,
win,
remote,
type,
bytesSent,
bytesReceived,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
RmaOpCompleteBlockingCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                        uint64_t eventPosition, void *userData,
                        OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                        uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaOpCompleteBlockingEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
RmaOpCompleteNonBlockingCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                           uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaOpCompleteNonBlockingEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaOpTestCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                              uint64_t eventPosition, void *userData,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef win, uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaOpTestEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode RmaOpCompleteRemoteCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef win,
                                        uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeRmaOpCompleteRemoteEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadForkCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_Paradigm model,
                               uint32_t numberOfRequestedThreads) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadForkEvent(location,
                                          time,
                                          attributes,
model,
numberOfRequestedThreads);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadJoinCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_Paradigm model) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadJoinEvent(location,
                                          time,
                                          attributes,
model);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadTeamBeginCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_CommRef threadTeam) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadTeamBeginEvent(location,
                                          time,
                                          attributes,
threadTeam);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadTeamEndCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  OTF2_CommRef threadTeam) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadTeamEndEvent(location,
                                          time,
                                          attributes,
threadTeam);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadAcquireLockCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_Paradigm model, uint32_t lockID,
                                      uint32_t acquisitionOrder) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadAcquireLockEvent(location,
                                          time,
                                          attributes,
model,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadReleaseLockCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_Paradigm model, uint32_t lockID,
                                      uint32_t acquisitionOrder) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadReleaseLockEvent(location,
                                          time,
                                          attributes,
model,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
ThreadTaskCreateCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                   uint64_t eventPosition, void *userData,
                   OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
                   uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadTaskCreateEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
ThreadTaskSwitchCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                   uint64_t eventPosition, void *userData,
                   OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
                   uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadTaskSwitchEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
ThreadTaskCompleteCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                     uint64_t eventPosition, void *userData,
                     OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
                     uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadTaskCompleteEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadCreateCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_CommRef threadContingent,
                                 uint64_t sequenceCount) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadCreateEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadBeginCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_CommRef threadContingent,
                                uint64_t sequenceCount) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadBeginEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadWaitCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_CommRef threadContingent,
                               uint64_t sequenceCount) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadWaitEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ThreadEndCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                              uint64_t eventPosition, void *userData,
                              OTF2_AttributeList *attributes,
                              OTF2_CommRef threadContingent,
                              uint64_t sequenceCount) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeThreadEndEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode CallingContextEnterCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CallingContextRef callingContext,
                                        uint32_t unwindDistance) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeCallingContextEnterEvent(location,
                                          time,
                                          attributes,
callingContext,
unwindDistance);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode CallingContextLeaveCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CallingContextRef callingContext) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeCallingContextLeaveEvent(location,
                                          time,
                                          attributes,
callingContext);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode CallingContextSampleCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes,
    OTF2_CallingContextRef callingContext, uint32_t unwindDistance,
    OTF2_InterruptGeneratorRef interruptGenerator) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeCallingContextSampleEvent(location,
                                          time,
                                          attributes,
callingContext,
unwindDistance,
interruptGenerator);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
IoCreateHandleCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                 uint64_t eventPosition, void *userData,
                 OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                 OTF2_IoAccessMode mode, OTF2_IoCreationFlag creationFlags,
                 OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoCreateHandleEvent(location,
                                          time,
                                          attributes,
handle,
mode,
creationFlags,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoDestroyHandleCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_IoHandleRef handle) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoDestroyHandleEvent(location,
                                          time,
                                          attributes,
handle);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
IoDuplicateHandleCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                    uint64_t eventPosition, void *userData,
                    OTF2_AttributeList *attributes, OTF2_IoHandleRef oldHandle,
                    OTF2_IoHandleRef newHandle, OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoDuplicateHandleEvent(location,
                                          time,
                                          attributes,
oldHandle,
newHandle,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoSeekCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes,
                           OTF2_IoHandleRef handle, int64_t offsetRequest,
                           OTF2_IoSeekOption whence, uint64_t offsetResult) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoSeekEvent(location,
                                          time,
                                          attributes,
handle,
offsetRequest,
whence,
offsetResult);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoChangeStatusFlagsCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        OTF2_IoHandleRef handle,
                                        OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoChangeStatusFlagsEvent(location,
                                          time,
                                          attributes,
handle,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoDeleteFileCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_IoParadigmRef ioParadigm,
                                 OTF2_IoFileRef file) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoDeleteFileEvent(location,
                                          time,
                                          attributes,
ioParadigm,
file);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoOperationBeginCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
    uint64_t bytesRequest, uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoOperationBeginEvent(location,
                                          time,
                                          attributes,
handle,
mode,
operationFlags,
bytesRequest,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoOperationTestCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_IoHandleRef handle,
                                    uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoOperationTestEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoOperationIssuedCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_IoHandleRef handle,
                                      uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoOperationIssuedEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
IoOperationCompleteCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                      uint64_t eventPosition, void *userData,
                      OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                      uint64_t bytesResult, uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoOperationCompleteEvent(location,
                                          time,
                                          attributes,
handle,
bytesResult,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoOperationCancelledCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         uint64_t matchingId) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoOperationCancelledEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoAcquireLockCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  OTF2_IoHandleRef handle,
                                  OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoAcquireLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoReleaseLockCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  OTF2_IoHandleRef handle,
                                  OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoReleaseLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode IoTryLockCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                              uint64_t eventPosition, void *userData,
                              OTF2_AttributeList *attributes,
                              OTF2_IoHandleRef handle, OTF2_LockType lockType) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeIoTryLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ProgramBeginCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_StringRef programName,
                                 uint32_t numberOfArguments,
                                 const OTF2_StringRef *programArguments) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeProgramBeginEvent(location,
                                          time,
                                          attributes,
programName,
numberOfArguments,
programArguments);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode ProgramEndCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               int64_t exitStatus) {
    // auto tr = static_cast<TraceReader *>(userData);
    /*tr->writer().writeProgramEndEvent(location,
                                          time,
                                          attributes,
exitStatus);*/
    return OTF2_CALLBACK_SUCCESS;
}

} // namespace event