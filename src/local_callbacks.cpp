#include <cassert>

#include <local_callbacks.hpp>
#include <local_reader.hpp>

namespace event
{

OTF2_CallbackCode
LocalBufferFlushCb(OTF2_LocationRef    location,
                   OTF2_TimeStamp      time,
                   uint64_t            eventPosition,
                   void *              userData,
                   OTF2_AttributeList *attributes,
                   OTF2_TimeStamp      stopTime)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleBufferFlushEvent(location, time, attributes, stopTime);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMeasurementOnOffCb(OTF2_LocationRef     location,
                        OTF2_TimeStamp       time,
                        uint64_t             eventPosition,
                        void *               userData,
                        OTF2_AttributeList * attributes,
                        OTF2_MeasurementMode measurementMode)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMeasurementOnOffEvent(location, time, attributes, measurementMode);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalEnterCb(OTF2_LocationRef    location,
             OTF2_TimeStamp      time,
             uint64_t            eventPosition,
             void *              userData,
             OTF2_AttributeList *attributes,
             OTF2_RegionRef      region)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleEnterEvent(location, time, attributes, region);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalLeaveCb(OTF2_LocationRef    location,
             OTF2_TimeStamp      time,
             uint64_t            eventPosition,
             void *              userData,
             OTF2_AttributeList *attributes,
             OTF2_RegionRef      region)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleLeaveEvent(location, time, attributes, region);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiSendCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            receiver,
               OTF2_CommRef        communicator,
               uint32_t            msgTag,
               uint64_t            msgLength)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiSendEvent(location, time, attributes, receiver, communicator, msgTag, msgLength);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiIsendCb(OTF2_LocationRef    location,
                OTF2_TimeStamp      time,
                uint64_t            eventPosition,
                void *              userData,
                OTF2_AttributeList *attributes,
                uint32_t            receiver,
                OTF2_CommRef        communicator,
                uint32_t            msgTag,
                uint64_t            msgLength,
                uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiIsendEvent(location, time, attributes, receiver, communicator, msgTag, msgLength, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiIsendCompleteCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiIsendCompleteEvent(location, time, attributes, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiIrecvRequestCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiIrecvRequestEvent(location, time, attributes, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiRecvCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            sender,
               OTF2_CommRef        communicator,
               uint32_t            msgTag,
               uint64_t            msgLength)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiRecvEvent(location, time, attributes, sender, communicator, msgTag, msgLength);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiIrecvCb(OTF2_LocationRef    location,
                OTF2_TimeStamp      time,
                uint64_t            eventPosition,
                void *              userData,
                OTF2_AttributeList *attributes,
                uint32_t            sender,
                OTF2_CommRef        communicator,
                uint32_t            msgTag,
                uint64_t            msgLength,
                uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiIrecvEvent(location, time, attributes, sender, communicator, msgTag, msgLength, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiRequestTestCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiRequestTestEvent(location, time, attributes, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiRequestCancelledCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           uint64_t            requestID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiRequestCancelledEvent(location, time, attributes, requestID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiCollectiveBeginCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiCollectiveBeginEvent(location, time, attributes);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMpiCollectiveEndCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CollectiveOp   collectiveOp,
                        OTF2_CommRef        communicator,
                        uint32_t            root,
                        uint64_t            sizeSent,
                        uint64_t            sizeReceived)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMpiCollectiveEndEvent(
        location, time, attributes, collectiveOp, communicator, root, sizeSent, sizeReceived);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpForkCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            numberOfRequestedThreads)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpForkEvent(location, time, attributes, numberOfRequestedThreads);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpJoinCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpJoinEvent(location, time, attributes);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpAcquireLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint32_t            lockID,
                      uint32_t            acquisitionOrder)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpAcquireLockEvent(location, time, attributes, lockID, acquisitionOrder);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpReleaseLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint32_t            lockID,
                      uint32_t            acquisitionOrder)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpReleaseLockEvent(location, time, attributes, lockID, acquisitionOrder);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpTaskCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     uint64_t            taskID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpTaskCreateEvent(location, time, attributes, taskID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpTaskSwitchCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     uint64_t            taskID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpTaskSwitchEvent(location, time, attributes, taskID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalOmpTaskCompleteCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       uint64_t            taskID)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleOmpTaskCompleteEvent(location, time, attributes, taskID);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalMetricCb(OTF2_LocationRef        location,
              OTF2_TimeStamp          time,
              uint64_t                eventPosition,
              void *                  userData,
              OTF2_AttributeList *    attributes,
              OTF2_MetricRef          metric,
              uint8_t                 numberOfMetrics,
              const OTF2_Type *       typeIDs,
              const OTF2_MetricValue *metricValues)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleMetricEvent(location, time, attributes, metric, numberOfMetrics, typeIDs, metricValues);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalParameterStringCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_ParameterRef   parameter,
                       OTF2_StringRef      string)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleParameterStringEvent(location, time, attributes, parameter, string);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalParameterIntCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_ParameterRef   parameter,
                    int64_t             value)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleParameterIntEvent(location, time, attributes, parameter, value);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalParameterUnsignedIntCb(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            uint64_t            eventPosition,
                            void *              userData,
                            OTF2_AttributeList *attributes,
                            OTF2_ParameterRef   parameter,
                            uint64_t            value)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleParameterUnsignedIntEvent(location, time, attributes, parameter, value);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaWinCreateCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_RmaWinRef      win)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaWinCreateEvent(location, time, attributes, win);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaWinDestroyCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_RmaWinRef      win)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaWinDestroyEvent(location, time, attributes, win);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaCollectiveBeginCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaCollectiveBeginEvent(location, time, attributes);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaCollectiveEndCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CollectiveOp   collectiveOp,
                        OTF2_RmaSyncLevel   syncLevel,
                        OTF2_RmaWinRef      win,
                        uint32_t            root,
                        uint64_t            bytesSent,
                        uint64_t            bytesReceived)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaCollectiveEndEvent(
        location, time, attributes, collectiveOp, syncLevel, win, root, bytesSent, bytesReceived);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaGroupSyncCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_RmaSyncLevel   syncLevel,
                    OTF2_RmaWinRef      win,
                    OTF2_GroupRef       group)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaGroupSyncEvent(location, time, attributes, syncLevel, win, group);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaRequestLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId,
                      OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaRequestLockEvent(location, time, attributes, win, remote, lockId, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaAcquireLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId,
                      OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaAcquireLockEvent(location, time, attributes, win, remote, lockId, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaTryLockCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_RmaWinRef      win,
                  uint32_t            remote,
                  uint64_t            lockId,
                  OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaTryLockEvent(location, time, attributes, win, remote, lockId, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaReleaseLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaReleaseLockEvent(location, time, attributes, win, remote, lockId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaSyncCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               OTF2_RmaWinRef      win,
               uint32_t            remote,
               OTF2_RmaSyncType    syncType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaSyncEvent(location, time, attributes, win, remote, syncType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaWaitChangeCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_RmaWinRef      win)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaWaitChangeEvent(location, time, attributes, win);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaPutCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_RmaWinRef      win,
              uint32_t            remote,
              uint64_t            bytes,
              uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaPutEvent(location, time, attributes, win, remote, bytes, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaGetCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_RmaWinRef      win,
              uint32_t            remote,
              uint64_t            bytes,
              uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaGetEvent(location, time, attributes, win, remote, bytes, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaAtomicCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_RmaWinRef      win,
                 uint32_t            remote,
                 OTF2_RmaAtomicType  type,
                 uint64_t            bytesSent,
                 uint64_t            bytesReceived,
                 uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaAtomicEvent(
        location, time, attributes, win, remote, type, bytesSent, bytesReceived, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpCompleteBlockingCb(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             uint64_t            eventPosition,
                             void *              userData,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win,
                             uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaOpCompleteBlockingEvent(location, time, attributes, win, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpCompleteNonBlockingCb(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                uint64_t            eventPosition,
                                void *              userData,
                                OTF2_AttributeList *attributes,
                                OTF2_RmaWinRef      win,
                                uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaOpCompleteNonBlockingEvent(location, time, attributes, win, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpTestCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_RmaWinRef      win,
                 uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaOpTestEvent(location, time, attributes, win, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalRmaOpCompleteRemoteCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_RmaWinRef      win,
                           uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleRmaOpCompleteRemoteEvent(location, time, attributes, win, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadForkCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_Paradigm       model,
                  uint32_t            numberOfRequestedThreads)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadForkEvent(location, time, attributes, model, numberOfRequestedThreads);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadJoinCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_Paradigm       model)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadJoinEvent(location, time, attributes, model);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTeamBeginCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_CommRef        threadTeam)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadTeamBeginEvent(location, time, attributes, threadTeam);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTeamEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_CommRef        threadTeam)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadTeamEndEvent(location, time, attributes, threadTeam);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadAcquireLockCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_Paradigm       model,
                         uint32_t            lockID,
                         uint32_t            acquisitionOrder)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadAcquireLockEvent(location, time, attributes, model, lockID, acquisitionOrder);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadReleaseLockCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_Paradigm       model,
                         uint32_t            lockID,
                         uint32_t            acquisitionOrder)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadReleaseLockEvent(location, time, attributes, model, lockID, acquisitionOrder);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTaskCreateCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CommRef        threadTeam,
                        uint32_t            creatingThread,
                        uint32_t            generationNumber)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadTaskCreateEvent(location, time, attributes, threadTeam, creatingThread, generationNumber);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTaskSwitchCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CommRef        threadTeam,
                        uint32_t            creatingThread,
                        uint32_t            generationNumber)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadTaskSwitchEvent(location, time, attributes, threadTeam, creatingThread, generationNumber);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadTaskCompleteCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes,
                          OTF2_CommRef        threadTeam,
                          uint32_t            creatingThread,
                          uint32_t            generationNumber)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadTaskCompleteEvent(
        location, time, attributes, threadTeam, creatingThread, generationNumber);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadCreateCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_CommRef        threadContingent,
                    uint64_t            sequenceCount)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadCreateEvent(location, time, attributes, threadContingent, sequenceCount);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadBeginCb(OTF2_LocationRef    location,
                   OTF2_TimeStamp      time,
                   uint64_t            eventPosition,
                   void *              userData,
                   OTF2_AttributeList *attributes,
                   OTF2_CommRef        threadContingent,
                   uint64_t            sequenceCount)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadBeginEvent(location, time, attributes, threadContingent, sequenceCount);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadWaitCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_CommRef        threadContingent,
                  uint64_t            sequenceCount)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadWaitEvent(location, time, attributes, threadContingent, sequenceCount);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalThreadEndCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_CommRef        threadContingent,
                 uint64_t            sequenceCount)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleThreadEndEvent(location, time, attributes, threadContingent, sequenceCount);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCallingContextEnterCb(OTF2_LocationRef       location,
                           OTF2_TimeStamp         time,
                           uint64_t               eventPosition,
                           void *                 userData,
                           OTF2_AttributeList *   attributes,
                           OTF2_CallingContextRef callingContext,
                           uint32_t               unwindDistance)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleCallingContextEnterEvent(location, time, attributes, callingContext, unwindDistance);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCallingContextLeaveCb(OTF2_LocationRef       location,
                           OTF2_TimeStamp         time,
                           uint64_t               eventPosition,
                           void *                 userData,
                           OTF2_AttributeList *   attributes,
                           OTF2_CallingContextRef callingContext)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleCallingContextLeaveEvent(location, time, attributes, callingContext);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalCallingContextSampleCb(OTF2_LocationRef           location,
                            OTF2_TimeStamp             time,
                            uint64_t                   eventPosition,
                            void *                     userData,
                            OTF2_AttributeList *       attributes,
                            OTF2_CallingContextRef     callingContext,
                            uint32_t                   unwindDistance,
                            OTF2_InterruptGeneratorRef interruptGenerator)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleCallingContextSampleEvent(
        location, time, attributes, callingContext, unwindDistance, interruptGenerator);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoCreateHandleCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_IoHandleRef    handle,
                      OTF2_IoAccessMode   mode,
                      OTF2_IoCreationFlag creationFlags,
                      OTF2_IoStatusFlag   statusFlags)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoCreateHandleEvent(location, time, attributes, handle, mode, creationFlags, statusFlags);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoDestroyHandleCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_IoHandleRef    handle)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoDestroyHandleEvent(location, time, attributes, handle);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoDuplicateHandleCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    oldHandle,
                         OTF2_IoHandleRef    newHandle,
                         OTF2_IoStatusFlag   statusFlags)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoDuplicateHandleEvent(location, time, attributes, oldHandle, newHandle, statusFlags);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoSeekCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_IoHandleRef    handle,
              int64_t             offsetRequest,
              OTF2_IoSeekOption   whence,
              uint64_t            offsetResult)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoSeekEvent(location, time, attributes, handle, offsetRequest, whence, offsetResult);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoChangeStatusFlagsCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_IoHandleRef    handle,
                           OTF2_IoStatusFlag   statusFlags)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoChangeStatusFlagsEvent(location, time, attributes, handle, statusFlags);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoDeleteFileCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_IoParadigmRef  ioParadigm,
                    OTF2_IoFileRef      file)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoDeleteFileEvent(location, time, attributes, ioParadigm, file);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationBeginCb(OTF2_LocationRef     location,
                        OTF2_TimeStamp       time,
                        uint64_t             eventPosition,
                        void *               userData,
                        OTF2_AttributeList * attributes,
                        OTF2_IoHandleRef     handle,
                        OTF2_IoOperationMode mode,
                        OTF2_IoOperationFlag operationFlags,
                        uint64_t             bytesRequest,
                        uint64_t             matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoOperationBeginEvent(
        location, time, attributes, handle, mode, operationFlags, bytesRequest, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationTestCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_IoHandleRef    handle,
                       uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoOperationTestEvent(location, time, attributes, handle, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationIssuedCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    handle,
                         uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoOperationIssuedEvent(location, time, attributes, handle, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationCompleteCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_IoHandleRef    handle,
                           uint64_t            bytesResult,
                           uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoOperationCompleteEvent(location, time, attributes, handle, bytesResult, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoOperationCancelledCb(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            uint64_t            eventPosition,
                            void *              userData,
                            OTF2_AttributeList *attributes,
                            OTF2_IoHandleRef    handle,
                            uint64_t            matchingId)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoOperationCancelledEvent(location, time, attributes, handle, matchingId);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_IoHandleRef    handle,
                     OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoAcquireLockEvent(location, time, attributes, handle, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_IoHandleRef    handle,
                     OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoReleaseLockEvent(location, time, attributes, handle, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalIoTryLockCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_IoHandleRef    handle,
                 OTF2_LockType       lockType)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleIoTryLockEvent(location, time, attributes, handle, lockType);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalProgramBeginCb(OTF2_LocationRef      location,
                    OTF2_TimeStamp        time,
                    uint64_t              eventPosition,
                    void *                userData,
                    OTF2_AttributeList *  attributes,
                    OTF2_StringRef        programName,
                    uint32_t              numberOfArguments,
                    const OTF2_StringRef *programArguments)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleProgramBeginEvent(location, time, attributes, programName, numberOfArguments, programArguments);

    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalProgramEndCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  int64_t             exitStatus)
{
    auto *tr = static_cast<LocalReader *>(userData);
    assert(tr != nullptr);

    tr->handler().handleProgramEndEvent(location, time, attributes, exitStatus);

    return OTF2_CALLBACK_SUCCESS;
}

} // namespace event

namespace definition
{

OTF2_CallbackCode
LocalMappingTableCb(void *userData, OTF2_MappingType mappingType, const OTF2_IdMap *idMap)
{
    auto * tr            = static_cast<ReaderLocationPair *>(userData);
    size_t self_location = tr->second;

    tr->first.handler().handleLocalMappingTable(self_location, mappingType, idMap);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
LocalClockOffsetCb(void *userData, OTF2_TimeStamp time, int64_t offset, double standardDeviation)
{
    auto * tr            = static_cast<ReaderLocationPair *>(userData);
    size_t self_location = tr->second;

    tr->first.handler().handleLocalClockOffset(self_location, time, offset, standardDeviation);
    return OTF2_CALLBACK_SUCCESS;
}

} // namespace definition