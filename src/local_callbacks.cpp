#include <local_callbacks.hpp>
#include <local_reader.hpp>

namespace event {

OTF2_CallbackCode LocalBufferFlushCb(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     uint64_t eventPosition, void *userData,
                                     OTF2_AttributeList *attributes,
                                     OTF2_TimeStamp stopTime) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeBufferFlushEvent(location,
                                          time,
                                          attributes,
stopTime);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMeasurementOnOffCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                        uint64_t eventPosition, void *userData,
                        OTF2_AttributeList *attributes,
                        OTF2_MeasurementMode measurementMode) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMeasurementOnOffEvent(location,
                                          time,
                                          attributes,
measurementMode);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalEnterCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_RegionRef region) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeEnterEvent(location,
                                          time,
                                          attributes,
region);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalLeaveCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                               uint64_t eventPosition, void *userData,
                               OTF2_AttributeList *attributes,
                               OTF2_RegionRef region) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeLeaveEvent(location,
                                          time,
                                          attributes,
region);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiSendCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 uint32_t receiver, OTF2_CommRef communicator,
                                 uint32_t msgTag, uint64_t msgLength) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiSendEvent(location,
                                          time,
                                          attributes,
receiver,
communicator,
msgTag,
msgLength);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiIsendCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  uint32_t receiver, OTF2_CommRef communicator,
                                  uint32_t msgTag, uint64_t msgLength,
                                  uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
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

OTF2_CallbackCode
LocalMpiIsendCompleteCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                        uint64_t eventPosition, void *userData,
                        OTF2_AttributeList *attributes, uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiIsendCompleteEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiIrecvRequestCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiIrecvRequestEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiRecvCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 uint32_t sender, OTF2_CommRef communicator,
                                 uint32_t msgTag, uint64_t msgLength) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiRecvEvent(location,
                                          time,
                                          attributes,
sender,
communicator,
msgTag,
msgLength);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiIrecvCb(OTF2_LocationRef location,
                                  OTF2_TimeStamp time, uint64_t eventPosition,
                                  void *userData,
                                  OTF2_AttributeList *attributes,
                                  uint32_t sender, OTF2_CommRef communicator,
                                  uint32_t msgTag, uint64_t msgLength,
                                  uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
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

OTF2_CallbackCode LocalMpiRequestTestCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiRequestTestEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiRequestCancelledCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes, uint64_t requestID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiRequestCancelledEvent(location,
                                          time,
                                          attributes,
requestID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiCollectiveBeginCb(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            uint64_t eventPosition,
                                            void *userData,
                                            OTF2_AttributeList *attributes) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMpiCollectiveBeginEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMpiCollectiveEndCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes,
    OTF2_CollectiveOp collectiveOp, OTF2_CommRef communicator, uint32_t root,
    uint64_t sizeSent, uint64_t sizeReceived) {
    // auto tr = static_cast<LocalReader *>(userData);
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

OTF2_CallbackCode LocalOmpForkCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 uint32_t numberOfRequestedThreads) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpForkEvent(location,
                                          time,
                                          attributes,
numberOfRequestedThreads);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpJoinCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpJoinEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpAcquireLockCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        uint32_t lockID,
                                        uint32_t acquisitionOrder) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpAcquireLockEvent(location,
                                          time,
                                          attributes,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpReleaseLockCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        uint32_t lockID,
                                        uint32_t acquisitionOrder) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpReleaseLockEvent(location,
                                          time,
                                          attributes,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpTaskCreateCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       uint64_t taskID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpTaskCreateEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpTaskSwitchCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       uint64_t taskID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpTaskSwitchEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalOmpTaskCompleteCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         uint64_t taskID) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeOmpTaskCompleteEvent(location,
                                          time,
                                          attributes,
taskID);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMetricCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_MetricRef metric, uint8_t numberOfMetrics,
                                const OTF2_Type *typeIDs,
                                const OTF2_MetricValue *metricValues) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMetricEvent(location,
                                          time,
                                          attributes,
metric,
numberOfMetrics,
typeIDs,
metricValues);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalParameterStringCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_ParameterRef parameter,
                                         OTF2_StringRef string) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeParameterStringEvent(location,
                                          time,
                                          attributes,
parameter,
string);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalParameterIntCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_ParameterRef parameter,
                                      int64_t value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeParameterIntEvent(location,
                                          time,
                                          attributes,
parameter,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalParameterUnsignedIntCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes,
                            OTF2_ParameterRef parameter, uint64_t value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeParameterUnsignedIntEvent(location,
                                          time,
                                          attributes,
parameter,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaWinCreateCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_RmaWinRef win) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaWinCreateEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaWinDestroyCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       OTF2_RmaWinRef win) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaWinDestroyEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaCollectiveBeginCb(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            uint64_t eventPosition,
                                            void *userData,
                                            OTF2_AttributeList *attributes) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaCollectiveBeginEvent(location,
                                          time,
                                          attributes);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaCollectiveEndCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes,
    OTF2_CollectiveOp collectiveOp, OTF2_RmaSyncLevel syncLevel,
    OTF2_RmaWinRef win, uint32_t root, uint64_t bytesSent,
    uint64_t bytesReceived) {
    // auto tr = static_cast<LocalReader *>(userData);
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

OTF2_CallbackCode LocalRmaGroupSyncCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_RmaSyncLevel syncLevel,
                                      OTF2_RmaWinRef win, OTF2_GroupRef group) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaGroupSyncEvent(location,
                                          time,
                                          attributes,
syncLevel,
win,
group);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaRequestLockCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
    uint32_t remote, uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaRequestLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaAcquireLockCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
    uint32_t remote, uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaAcquireLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaTryLockCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_RmaWinRef win, uint32_t remote,
                                    uint64_t lockId, OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaTryLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaReleaseLockCb(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        uint64_t eventPosition, void *userData,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef win, uint32_t remote,
                                        uint64_t lockId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaReleaseLockEvent(location,
                                          time,
                                          attributes,
win,
remote,
lockId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaSyncCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 uint64_t eventPosition, void *userData,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RmaWinRef win, uint32_t remote,
                                 OTF2_RmaSyncType syncType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaSyncEvent(location,
                                          time,
                                          attributes,
win,
remote,
syncType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaWaitChangeCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       OTF2_RmaWinRef win) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaWaitChangeEvent(location,
                                          time,
                                          attributes,
win);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaPutCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_RmaWinRef win, uint32_t remote,
                                uint64_t bytes, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaPutEvent(location,
                                          time,
                                          attributes,
win,
remote,
bytes,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaGetCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_RmaWinRef win, uint32_t remote,
                                uint64_t bytes, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaGetEvent(location,
                                          time,
                                          attributes,
win,
remote,
bytes,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaAtomicCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                 uint64_t eventPosition, void *userData,
                 OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                 uint32_t remote, OTF2_RmaAtomicType type, uint64_t bytesSent,
                 uint64_t bytesReceived, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
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
LocalRmaOpCompleteBlockingCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                             uint64_t eventPosition, void *userData,
                             OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                             uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaOpCompleteBlockingEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpCompleteNonBlockingCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_RmaWinRef win, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaOpCompleteNonBlockingEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaOpTestCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaOpTestEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpCompleteRemoteCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                           uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaOpCompleteRemoteEvent(location,
                                          time,
                                          attributes,
win,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadForkCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_Paradigm model,
                                    uint32_t numberOfRequestedThreads) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadForkEvent(location,
                                          time,
                                          attributes,
model,
numberOfRequestedThreads);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadJoinCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_Paradigm model) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadJoinEvent(location,
                                          time,
                                          attributes,
model);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadTeamBeginCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_CommRef threadTeam) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadTeamBeginEvent(location,
                                          time,
                                          attributes,
threadTeam);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadTeamEndCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       OTF2_CommRef threadTeam) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadTeamEndEvent(location,
                                          time,
                                          attributes,
threadTeam);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadAcquireLockCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                         uint64_t eventPosition, void *userData,
                         OTF2_AttributeList *attributes, OTF2_Paradigm model,
                         uint32_t lockID, uint32_t acquisitionOrder) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadAcquireLockEvent(location,
                                          time,
                                          attributes,
model,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadReleaseLockCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                         uint64_t eventPosition, void *userData,
                         OTF2_AttributeList *attributes, OTF2_Paradigm model,
                         uint32_t lockID, uint32_t acquisitionOrder) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadReleaseLockEvent(location,
                                          time,
                                          attributes,
model,
lockID,
acquisitionOrder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTaskCreateCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                        uint64_t eventPosition, void *userData,
                        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
                        uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadTaskCreateEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTaskSwitchCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                        uint64_t eventPosition, void *userData,
                        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
                        uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadTaskSwitchEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadTaskCompleteCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
    uint32_t creatingThread, uint32_t generationNumber) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadTaskCompleteEvent(location,
                                          time,
                                          attributes,
threadTeam,
creatingThread,
generationNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadCreateCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_CommRef threadContingent,
                                      uint64_t sequenceCount) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadCreateEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadBeginCb(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     uint64_t eventPosition, void *userData,
                                     OTF2_AttributeList *attributes,
                                     OTF2_CommRef threadContingent,
                                     uint64_t sequenceCount) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadBeginEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadWaitCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    OTF2_CommRef threadContingent,
                                    uint64_t sequenceCount) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadWaitEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalThreadEndCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_CommRef threadContingent,
                                   uint64_t sequenceCount) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeThreadEndEvent(location,
                                          time,
                                          attributes,
threadContingent,
sequenceCount);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallingContextEnterCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes,
    OTF2_CallingContextRef callingContext, uint32_t unwindDistance) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallingContextEnterEvent(location,
                                          time,
                                          attributes,
callingContext,
unwindDistance);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCallingContextLeaveCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                           uint64_t eventPosition, void *userData,
                           OTF2_AttributeList *attributes,
                           OTF2_CallingContextRef callingContext) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallingContextLeaveEvent(location,
                                          time,
                                          attributes,
callingContext);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallingContextSampleCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes,
    OTF2_CallingContextRef callingContext, uint32_t unwindDistance,
    OTF2_InterruptGeneratorRef interruptGenerator) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallingContextSampleEvent(location,
                                          time,
                                          attributes,
callingContext,
unwindDistance,
interruptGenerator);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoCreateHandleCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                      uint64_t eventPosition, void *userData,
                      OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                      OTF2_IoAccessMode mode, OTF2_IoCreationFlag creationFlags,
                      OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoCreateHandleEvent(location,
                                          time,
                                          attributes,
handle,
mode,
creationFlags,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoDestroyHandleCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoDestroyHandleEvent(location,
                                          time,
                                          attributes,
handle);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoDuplicateHandleCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_IoHandleRef oldHandle,
    OTF2_IoHandleRef newHandle, OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoDuplicateHandleEvent(location,
                                          time,
                                          attributes,
oldHandle,
newHandle,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoSeekCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                                uint64_t eventPosition, void *userData,
                                OTF2_AttributeList *attributes,
                                OTF2_IoHandleRef handle, int64_t offsetRequest,
                                OTF2_IoSeekOption whence,
                                uint64_t offsetResult) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoSeekEvent(location,
                                          time,
                                          attributes,
handle,
offsetRequest,
whence,
offsetResult);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoChangeStatusFlagsCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoChangeStatusFlagsEvent(location,
                                          time,
                                          attributes,
handle,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoDeleteFileCb(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      uint64_t eventPosition, void *userData,
                                      OTF2_AttributeList *attributes,
                                      OTF2_IoParadigmRef ioParadigm,
                                      OTF2_IoFileRef file) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoDeleteFileEvent(location,
                                          time,
                                          attributes,
ioParadigm,
file);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoOperationBeginCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
    uint64_t bytesRequest, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
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

OTF2_CallbackCode LocalIoOperationTestCb(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         uint64_t eventPosition, void *userData,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoOperationTestEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationIssuedCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                         uint64_t eventPosition, void *userData,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef handle, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoOperationIssuedEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoOperationCompleteCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    uint64_t bytesResult, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoOperationCompleteEvent(location,
                                          time,
                                          attributes,
handle,
bytesResult,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationCancelledCb(OTF2_LocationRef location, OTF2_TimeStamp time,
                            uint64_t eventPosition, void *userData,
                            OTF2_AttributeList *attributes,
                            OTF2_IoHandleRef handle, uint64_t matchingId) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoOperationCancelledEvent(location,
                                          time,
                                          attributes,
handle,
matchingId);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoAcquireLockCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       OTF2_IoHandleRef handle,
                                       OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoAcquireLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoReleaseLockCb(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       uint64_t eventPosition, void *userData,
                                       OTF2_AttributeList *attributes,
                                       OTF2_IoHandleRef handle,
                                       OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoReleaseLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoTryLockCb(OTF2_LocationRef location,
                                   OTF2_TimeStamp time, uint64_t eventPosition,
                                   void *userData,
                                   OTF2_AttributeList *attributes,
                                   OTF2_IoHandleRef handle,
                                   OTF2_LockType lockType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoTryLockEvent(location,
                                          time,
                                          attributes,
handle,
lockType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalProgramBeginCb(
    OTF2_LocationRef location, OTF2_TimeStamp time, uint64_t eventPosition,
    void *userData, OTF2_AttributeList *attributes, OTF2_StringRef programName,
    uint32_t numberOfArguments, const OTF2_StringRef *programArguments) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeProgramBeginEvent(location,
                                          time,
                                          attributes,
programName,
numberOfArguments,
programArguments);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalProgramEndCb(OTF2_LocationRef location,
                                    OTF2_TimeStamp time, uint64_t eventPosition,
                                    void *userData,
                                    OTF2_AttributeList *attributes,
                                    int64_t exitStatus) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeProgramEndEvent(location,
                                          time,
                                          attributes,
exitStatus);*/
    return OTF2_CALLBACK_SUCCESS;
}

} // namespace event

namespace definition {

OTF2_CallbackCode LocalMappingTableCb(void *userData,
                                      OTF2_MappingType mappingType,
                                      const OTF2_IdMap *idMap) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMappingTableDef(location,
                                        attributes,
mappingType,
idMap);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalClockOffsetCb(void *userData, OTF2_TimeStamp time,
                                     int64_t offset, double standardDeviation) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeClockOffsetDef(location,
                                        attributes,
time,
offset,
standardDeviation);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalStringCb(void *userData, OTF2_StringRef self,
                                const char *string) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeStringDef(location,
                                        attributes,
self,
string);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalAttributeCb(void *userData, OTF2_AttributeRef self,
                                   OTF2_StringRef name,
                                   OTF2_StringRef description, OTF2_Type type) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeAttributeDef(location,
                                        attributes,
self,
name,
description,
type);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalSystemTreeNodeCb(void *userData,
                                        OTF2_SystemTreeNodeRef self,
                                        OTF2_StringRef name,
                                        OTF2_StringRef className,
                                        OTF2_SystemTreeNodeRef parent) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeSystemTreeNodeDef(location,
                                        attributes,
self,
name,
className,
parent);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalLocationGroupCb(void *userData, OTF2_LocationGroupRef self,
                     OTF2_StringRef name,
                     OTF2_LocationGroupType locationGroupType,
                     OTF2_SystemTreeNodeRef systemTreeParent) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeLocationGroupDef(location,
                                        attributes,
self,
name,
locationGroupType,
systemTreeParent);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalLocationCb(void *userData, OTF2_LocationRef self,
                                  OTF2_StringRef name,
                                  OTF2_LocationType locationType,
                                  uint64_t numberOfEvents,
                                  OTF2_LocationGroupRef locationGroup) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeLocationDef(location,
                                        attributes,
self,
name,
locationType,
numberOfEvents,
locationGroup);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRegionCb(void *userData, OTF2_RegionRef self, OTF2_StringRef name,
              OTF2_StringRef canonicalName, OTF2_StringRef description,
              OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
              OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
              uint32_t beginLineNumber, uint32_t endLineNumber) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRegionDef(location,
                                        attributes,
self,
name,
canonicalName,
description,
regionRole,
paradigm,
regionFlags,
sourceFile,
beginLineNumber,
endLineNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallsiteCb(void *userData, OTF2_CallsiteRef self,
                                  OTF2_StringRef sourceFile,
                                  uint32_t lineNumber,
                                  OTF2_RegionRef enteredRegion,
                                  OTF2_RegionRef leftRegion) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallsiteDef(location,
                                        attributes,
self,
sourceFile,
lineNumber,
enteredRegion,
leftRegion);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallpathCb(void *userData, OTF2_CallpathRef self,
                                  OTF2_CallpathRef parent,
                                  OTF2_RegionRef region) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallpathDef(location,
                                        attributes,
self,
parent,
region);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalGroupCb(void *userData, OTF2_GroupRef self,
                               OTF2_StringRef name, OTF2_GroupType groupType,
                               OTF2_Paradigm paradigm,
                               OTF2_GroupFlag groupFlags,
                               uint32_t numberOfMembers,
                               const uint64_t *members) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeGroupDef(location,
                                        attributes,
self,
name,
groupType,
paradigm,
groupFlags,
numberOfMembers,
members);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMetricMemberCb(void *userData, OTF2_MetricMemberRef self,
                                      OTF2_StringRef name,
                                      OTF2_StringRef description,
                                      OTF2_MetricType metricType,
                                      OTF2_MetricMode metricMode,
                                      OTF2_Type valueType, OTF2_Base base,
                                      int64_t exponent, OTF2_StringRef unit) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMetricMemberDef(location,
                                        attributes,
self,
name,
description,
metricType,
metricMode,
valueType,
base,
exponent,
unit);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMetricClassCb(void *userData, OTF2_MetricRef self,
                                     uint8_t numberOfMetrics,
                                     const OTF2_MetricMemberRef *metricMembers,
                                     OTF2_MetricOccurrence metricOccurrence,
                                     OTF2_RecorderKind recorderKind) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMetricClassDef(location,
                                        attributes,
self,
numberOfMetrics,
metricMembers,
metricOccurrence,
recorderKind);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMetricInstanceCb(void *userData, OTF2_MetricRef self,
                                        OTF2_MetricRef metricClass,
                                        OTF2_LocationRef recorder,
                                        OTF2_MetricScope metricScope,
                                        uint64_t scope) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMetricInstanceDef(location,
                                        attributes,
self,
metricClass,
recorder,
metricScope,
scope);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCommCb(void *userData, OTF2_CommRef self,
                              OTF2_StringRef name, OTF2_GroupRef group,
                              OTF2_CommRef parent) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCommDef(location,
                                        attributes,
self,
name,
group,
parent);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalParameterCb(void *userData, OTF2_ParameterRef self,
                                   OTF2_StringRef name,
                                   OTF2_ParameterType parameterType) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeParameterDef(location,
                                        attributes,
self,
name,
parameterType);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalRmaWinCb(void *userData, OTF2_RmaWinRef self,
                                OTF2_StringRef name, OTF2_CommRef comm) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeRmaWinDef(location,
                                        attributes,
self,
name,
comm);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalMetricClassRecorderCb(void *userData,
                                             OTF2_MetricRef metric,
                                             OTF2_LocationRef recorder) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeMetricClassRecorderDef(location,
                                        attributes,
metric,
recorder);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalSystemTreeNodePropertyCb(
    void *userData, OTF2_SystemTreeNodeRef systemTreeNode, OTF2_StringRef name,
    OTF2_Type type, OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeSystemTreeNodePropertyDef(location,
                                        attributes,
systemTreeNode,
name,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalSystemTreeNodeDomainCb(void *userData,
                            OTF2_SystemTreeNodeRef systemTreeNode,
                            OTF2_SystemTreeDomain systemTreeDomain) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeSystemTreeNodeDomainDef(location,
                                        attributes,
systemTreeNode,
systemTreeDomain);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalLocationGroupPropertyCb(
    void *userData, OTF2_LocationGroupRef locationGroup, OTF2_StringRef name,
    OTF2_Type type, OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeLocationGroupPropertyDef(location,
                                        attributes,
locationGroup,
name,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalLocationPropertyCb(void *userData,
                                          OTF2_LocationRef location,
                                          OTF2_StringRef name, OTF2_Type type,
                                          OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeLocationPropertyDef(location,
                                        attributes,
location,
name,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCartDimensionCb(void *userData,
                                       OTF2_CartDimensionRef self,
                                       OTF2_StringRef name, uint32_t size,
                                       OTF2_CartPeriodicity cartPeriodicity) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCartDimensionDef(location,
                                        attributes,
self,
name,
size,
cartPeriodicity);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCartTopologyCb(void *userData, OTF2_CartTopologyRef self,
                    OTF2_StringRef name, OTF2_CommRef communicator,
                    uint8_t numberOfDimensions,
                    const OTF2_CartDimensionRef *cartDimensions) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCartTopologyDef(location,
                                        attributes,
self,
name,
communicator,
numberOfDimensions,
cartDimensions);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCartCoordinateCb(void *userData,
                                        OTF2_CartTopologyRef cartTopology,
                                        uint32_t rank,
                                        uint8_t numberOfDimensions,
                                        const uint32_t *coordinates) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCartCoordinateDef(location,
                                        attributes,
cartTopology,
rank,
numberOfDimensions,
coordinates);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalSourceCodeLocationCb(void *userData,
                                            OTF2_SourceCodeLocationRef self,
                                            OTF2_StringRef file,
                                            uint32_t lineNumber) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeSourceCodeLocationDef(location,
                                        attributes,
self,
file,
lineNumber);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCallingContextCb(void *userData, OTF2_CallingContextRef self,
                      OTF2_RegionRef region,
                      OTF2_SourceCodeLocationRef sourceCodeLocation,
                      OTF2_CallingContextRef parent) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallingContextDef(location,
                                        attributes,
self,
region,
sourceCodeLocation,
parent);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallingContextPropertyCb(
    void *userData, OTF2_CallingContextRef callingContext, OTF2_StringRef name,
    OTF2_Type type, OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallingContextPropertyDef(location,
                                        attributes,
callingContext,
name,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalInterruptGeneratorCb(void *userData, OTF2_InterruptGeneratorRef self,
                          OTF2_StringRef name,
                          OTF2_InterruptGeneratorMode interruptGeneratorMode,
                          OTF2_Base base, int64_t exponent, uint64_t period) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeInterruptGeneratorDef(location,
                                        attributes,
self,
name,
interruptGeneratorMode,
base,
exponent,
period);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoFilePropertyCb(void *userData, OTF2_IoFileRef ioFile,
                                        OTF2_StringRef name, OTF2_Type type,
                                        OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoFilePropertyDef(location,
                                        attributes,
ioFile,
name,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoRegularFileCb(void *userData, OTF2_IoFileRef self,
                                       OTF2_StringRef name,
                                       OTF2_SystemTreeNodeRef scope) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoRegularFileDef(location,
                                        attributes,
self,
name,
scope);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoDirectoryCb(void *userData, OTF2_IoFileRef self,
                                     OTF2_StringRef name,
                                     OTF2_SystemTreeNodeRef scope) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoDirectoryDef(location,
                                        attributes,
self,
name,
scope);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalIoHandleCb(void *userData, OTF2_IoHandleRef self,
                                  OTF2_StringRef name, OTF2_IoFileRef file,
                                  OTF2_IoParadigmRef ioParadigm,
                                  OTF2_IoHandleFlag ioHandleFlags,
                                  OTF2_CommRef comm, OTF2_IoHandleRef parent) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoHandleDef(location,
                                        attributes,
self,
name,
file,
ioParadigm,
ioHandleFlags,
comm,
parent);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoPreCreatedHandleStateCb(void *userData, OTF2_IoHandleRef ioHandle,
                               OTF2_IoAccessMode mode,
                               OTF2_IoStatusFlag statusFlags) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeIoPreCreatedHandleStateDef(location,
                                        attributes,
ioHandle,
mode,
statusFlags);*/
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode LocalCallpathParameterCb(void *userData,
                                           OTF2_CallpathRef callpath,
                                           OTF2_ParameterRef parameter,
                                           OTF2_Type type,
                                           OTF2_AttributeValue value) {
    // auto tr = static_cast<LocalReader *>(userData);
    /*tr->writer().writeCallpathParameterDef(location,
                                        attributes,
callpath,
parameter,
type,
value);*/
    return OTF2_CALLBACK_SUCCESS;
}

} // namespace definition