#ifndef EVENT_CALLBACKS_HPP
#define EVENT_CALLBACKS_HPP

extern "C"
{
#include <otf2/otf2.h>
}

namespace event
{

OTF2_CallbackCode
LocalBufferFlushCb(OTF2_LocationRef    location,
                   OTF2_TimeStamp      time,
                   uint64_t            eventPosition,
                   void *              userData,
                   OTF2_AttributeList *attributes,
                   OTF2_TimeStamp      stopTime);

OTF2_CallbackCode
LocalMeasurementOnOffCb(OTF2_LocationRef     location,
                        OTF2_TimeStamp       time,
                        uint64_t             eventPosition,
                        void *               userData,
                        OTF2_AttributeList * attributes,
                        OTF2_MeasurementMode measurementMode);

OTF2_CallbackCode
LocalEnterCb(OTF2_LocationRef    location,
             OTF2_TimeStamp      time,
             uint64_t            eventPosition,
             void *              userData,
             OTF2_AttributeList *attributes,
             OTF2_RegionRef      region);

OTF2_CallbackCode
LocalLeaveCb(OTF2_LocationRef    location,
             OTF2_TimeStamp      time,
             uint64_t            eventPosition,
             void *              userData,
             OTF2_AttributeList *attributes,
             OTF2_RegionRef      region);

OTF2_CallbackCode
LocalMpiSendCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            receiver,
               OTF2_CommRef        communicator,
               uint32_t            msgTag,
               uint64_t            msgLength);

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
                uint64_t            requestID);

OTF2_CallbackCode
LocalMpiIsendCompleteCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        uint64_t            requestID);

OTF2_CallbackCode
LocalMpiIrecvRequestCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       uint64_t            requestID);

OTF2_CallbackCode
LocalMpiRecvCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            sender,
               OTF2_CommRef        communicator,
               uint32_t            msgTag,
               uint64_t            msgLength);

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
                uint64_t            requestID);

OTF2_CallbackCode
LocalMpiRequestTestCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint64_t            requestID);

OTF2_CallbackCode
LocalMpiRequestCancelledCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           uint64_t            requestID);

OTF2_CallbackCode
LocalMpiCollectiveBeginCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes);

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
                        uint64_t            sizeReceived);

OTF2_CallbackCode
LocalOmpForkCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               uint32_t            numberOfRequestedThreads);

OTF2_CallbackCode
LocalOmpJoinCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes);

OTF2_CallbackCode
LocalOmpAcquireLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint32_t            lockID,
                      uint32_t            acquisitionOrder);

OTF2_CallbackCode
LocalOmpReleaseLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      uint32_t            lockID,
                      uint32_t            acquisitionOrder);

OTF2_CallbackCode
LocalOmpTaskCreateCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     uint64_t            taskID);

OTF2_CallbackCode
LocalOmpTaskSwitchCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     uint64_t            taskID);

OTF2_CallbackCode
LocalOmpTaskCompleteCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       uint64_t            taskID);

OTF2_CallbackCode
LocalMetricCb(OTF2_LocationRef        location,
              OTF2_TimeStamp          time,
              uint64_t                eventPosition,
              void *                  userData,
              OTF2_AttributeList *    attributes,
              OTF2_MetricRef          metric,
              uint8_t                 numberOfMetrics,
              const OTF2_Type *       typeIDs,
              const OTF2_MetricValue *metricValues);

OTF2_CallbackCode
LocalParameterStringCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_ParameterRef   parameter,
                       OTF2_StringRef      string);

OTF2_CallbackCode
LocalParameterIntCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_ParameterRef   parameter,
                    int64_t             value);

OTF2_CallbackCode
LocalParameterUnsignedIntCb(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            uint64_t            eventPosition,
                            void *              userData,
                            OTF2_AttributeList *attributes,
                            OTF2_ParameterRef   parameter,
                            uint64_t            value);

OTF2_CallbackCode
LocalRmaWinCreateCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_RmaWinRef      win);

OTF2_CallbackCode
LocalRmaWinDestroyCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_RmaWinRef      win);

OTF2_CallbackCode
LocalRmaCollectiveBeginCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes);

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
                        uint64_t            bytesReceived);

OTF2_CallbackCode
LocalRmaGroupSyncCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_RmaSyncLevel   syncLevel,
                    OTF2_RmaWinRef      win,
                    OTF2_GroupRef       group);

OTF2_CallbackCode
LocalRmaRequestLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId,
                      OTF2_LockType       lockType);

OTF2_CallbackCode
LocalRmaAcquireLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId,
                      OTF2_LockType       lockType);

OTF2_CallbackCode
LocalRmaTryLockCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_RmaWinRef      win,
                  uint32_t            remote,
                  uint64_t            lockId,
                  OTF2_LockType       lockType);

OTF2_CallbackCode
LocalRmaReleaseLockCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            lockId);

OTF2_CallbackCode
LocalRmaSyncCb(OTF2_LocationRef    location,
               OTF2_TimeStamp      time,
               uint64_t            eventPosition,
               void *              userData,
               OTF2_AttributeList *attributes,
               OTF2_RmaWinRef      win,
               uint32_t            remote,
               OTF2_RmaSyncType    syncType);

OTF2_CallbackCode
LocalRmaWaitChangeCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_RmaWinRef      win);

OTF2_CallbackCode
LocalRmaPutCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_RmaWinRef      win,
              uint32_t            remote,
              uint64_t            bytes,
              uint64_t            matchingId);

OTF2_CallbackCode
LocalRmaGetCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_RmaWinRef      win,
              uint32_t            remote,
              uint64_t            bytes,
              uint64_t            matchingId);

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
                 uint64_t            matchingId);

OTF2_CallbackCode
LocalRmaOpCompleteBlockingCb(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             uint64_t            eventPosition,
                             void *              userData,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win,
                             uint64_t            matchingId);

OTF2_CallbackCode
LocalRmaOpCompleteNonBlockingCb(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                uint64_t            eventPosition,
                                void *              userData,
                                OTF2_AttributeList *attributes,
                                OTF2_RmaWinRef      win,
                                uint64_t            matchingId);

OTF2_CallbackCode
LocalRmaOpTestCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_RmaWinRef      win,
                 uint64_t            matchingId);

OTF2_CallbackCode
LocalRmaOpCompleteRemoteCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_RmaWinRef      win,
                           uint64_t            matchingId);

OTF2_CallbackCode
LocalThreadForkCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_Paradigm       model,
                  uint32_t            numberOfRequestedThreads);

OTF2_CallbackCode
LocalThreadJoinCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_Paradigm       model);

OTF2_CallbackCode
LocalThreadTeamBeginCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_CommRef        threadTeam);

OTF2_CallbackCode
LocalThreadTeamEndCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_CommRef        threadTeam);

OTF2_CallbackCode
LocalThreadAcquireLockCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_Paradigm       model,
                         uint32_t            lockID,
                         uint32_t            acquisitionOrder);

OTF2_CallbackCode
LocalThreadReleaseLockCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_Paradigm       model,
                         uint32_t            lockID,
                         uint32_t            acquisitionOrder);

OTF2_CallbackCode
LocalThreadTaskCreateCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CommRef        threadTeam,
                        uint32_t            creatingThread,
                        uint32_t            generationNumber);

OTF2_CallbackCode
LocalThreadTaskSwitchCb(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        uint64_t            eventPosition,
                        void *              userData,
                        OTF2_AttributeList *attributes,
                        OTF2_CommRef        threadTeam,
                        uint32_t            creatingThread,
                        uint32_t            generationNumber);

OTF2_CallbackCode
LocalThreadTaskCompleteCb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void *              userData,
                          OTF2_AttributeList *attributes,
                          OTF2_CommRef        threadTeam,
                          uint32_t            creatingThread,
                          uint32_t            generationNumber);

OTF2_CallbackCode
LocalThreadCreateCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_CommRef        threadContingent,
                    uint64_t            sequenceCount);

OTF2_CallbackCode
LocalThreadBeginCb(OTF2_LocationRef    location,
                   OTF2_TimeStamp      time,
                   uint64_t            eventPosition,
                   void *              userData,
                   OTF2_AttributeList *attributes,
                   OTF2_CommRef        threadContingent,
                   uint64_t            sequenceCount);

OTF2_CallbackCode
LocalThreadWaitCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  OTF2_CommRef        threadContingent,
                  uint64_t            sequenceCount);

OTF2_CallbackCode
LocalThreadEndCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_CommRef        threadContingent,
                 uint64_t            sequenceCount);

OTF2_CallbackCode
LocalCallingContextEnterCb(OTF2_LocationRef       location,
                           OTF2_TimeStamp         time,
                           uint64_t               eventPosition,
                           void *                 userData,
                           OTF2_AttributeList *   attributes,
                           OTF2_CallingContextRef callingContext,
                           uint32_t               unwindDistance);

OTF2_CallbackCode
LocalCallingContextLeaveCb(OTF2_LocationRef       location,
                           OTF2_TimeStamp         time,
                           uint64_t               eventPosition,
                           void *                 userData,
                           OTF2_AttributeList *   attributes,
                           OTF2_CallingContextRef callingContext);

OTF2_CallbackCode
LocalCallingContextSampleCb(OTF2_LocationRef           location,
                            OTF2_TimeStamp             time,
                            uint64_t                   eventPosition,
                            void *                     userData,
                            OTF2_AttributeList *       attributes,
                            OTF2_CallingContextRef     callingContext,
                            uint32_t                   unwindDistance,
                            OTF2_InterruptGeneratorRef interruptGenerator);

OTF2_CallbackCode
LocalIoCreateHandleCb(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      uint64_t            eventPosition,
                      void *              userData,
                      OTF2_AttributeList *attributes,
                      OTF2_IoHandleRef    handle,
                      OTF2_IoAccessMode   mode,
                      OTF2_IoCreationFlag creationFlags,
                      OTF2_IoStatusFlag   statusFlags);

OTF2_CallbackCode
LocalIoDestroyHandleCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_IoHandleRef    handle);

OTF2_CallbackCode
LocalIoDuplicateHandleCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    oldHandle,
                         OTF2_IoHandleRef    newHandle,
                         OTF2_IoStatusFlag   statusFlags);

OTF2_CallbackCode
LocalIoSeekCb(OTF2_LocationRef    location,
              OTF2_TimeStamp      time,
              uint64_t            eventPosition,
              void *              userData,
              OTF2_AttributeList *attributes,
              OTF2_IoHandleRef    handle,
              int64_t             offsetRequest,
              OTF2_IoSeekOption   whence,
              uint64_t            offsetResult);

OTF2_CallbackCode
LocalIoChangeStatusFlagsCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_IoHandleRef    handle,
                           OTF2_IoStatusFlag   statusFlags);

OTF2_CallbackCode
LocalIoDeleteFileCb(OTF2_LocationRef    location,
                    OTF2_TimeStamp      time,
                    uint64_t            eventPosition,
                    void *              userData,
                    OTF2_AttributeList *attributes,
                    OTF2_IoParadigmRef  ioParadigm,
                    OTF2_IoFileRef      file);

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
                        uint64_t             matchingId);

OTF2_CallbackCode
LocalIoOperationTestCb(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       uint64_t            eventPosition,
                       void *              userData,
                       OTF2_AttributeList *attributes,
                       OTF2_IoHandleRef    handle,
                       uint64_t            matchingId);

OTF2_CallbackCode
LocalIoOperationIssuedCb(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         uint64_t            eventPosition,
                         void *              userData,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    handle,
                         uint64_t            matchingId);

OTF2_CallbackCode
LocalIoOperationCompleteCb(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           uint64_t            eventPosition,
                           void *              userData,
                           OTF2_AttributeList *attributes,
                           OTF2_IoHandleRef    handle,
                           uint64_t            bytesResult,
                           uint64_t            matchingId);

OTF2_CallbackCode
LocalIoOperationCancelledCb(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            uint64_t            eventPosition,
                            void *              userData,
                            OTF2_AttributeList *attributes,
                            OTF2_IoHandleRef    handle,
                            uint64_t            matchingId);

OTF2_CallbackCode
LocalIoAcquireLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_IoHandleRef    handle,
                     OTF2_LockType       lockType);

OTF2_CallbackCode
LocalIoReleaseLockCb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void *              userData,
                     OTF2_AttributeList *attributes,
                     OTF2_IoHandleRef    handle,
                     OTF2_LockType       lockType);

OTF2_CallbackCode
LocalIoTryLockCb(OTF2_LocationRef    location,
                 OTF2_TimeStamp      time,
                 uint64_t            eventPosition,
                 void *              userData,
                 OTF2_AttributeList *attributes,
                 OTF2_IoHandleRef    handle,
                 OTF2_LockType       lockType);

OTF2_CallbackCode
LocalProgramBeginCb(OTF2_LocationRef      location,
                    OTF2_TimeStamp        time,
                    uint64_t              eventPosition,
                    void *                userData,
                    OTF2_AttributeList *  attributes,
                    OTF2_StringRef        programName,
                    uint32_t              numberOfArguments,
                    const OTF2_StringRef *programArguments);

OTF2_CallbackCode
LocalProgramEndCb(OTF2_LocationRef    location,
                  OTF2_TimeStamp      time,
                  uint64_t            eventPosition,
                  void *              userData,
                  OTF2_AttributeList *attributes,
                  int64_t             exitStatus);

} // namespace event

namespace definition
{

OTF2_CallbackCode
LocalMappingTableCb(void *userData, OTF2_MappingType mappingType, const OTF2_IdMap *idMap);

OTF2_CallbackCode
LocalClockOffsetCb(void *userData, OTF2_TimeStamp time, int64_t offset, double standardDeviation);

OTF2_CallbackCode
LocalStringCb(void *userData, OTF2_StringRef self, const char *string);

OTF2_CallbackCode
LocalAttributeCb(
    void *userData, OTF2_AttributeRef self, OTF2_StringRef name, OTF2_StringRef description, OTF2_Type type);

OTF2_CallbackCode
LocalSystemTreeNodeCb(void *                 userData,
                      OTF2_SystemTreeNodeRef self,
                      OTF2_StringRef         name,
                      OTF2_StringRef         className,
                      OTF2_SystemTreeNodeRef parent);

OTF2_CallbackCode
LocalLocationGroupCb(void *                 userData,
                     OTF2_LocationGroupRef  self,
                     OTF2_StringRef         name,
                     OTF2_LocationGroupType locationGroupType,
                     OTF2_SystemTreeNodeRef systemTreeParent);

OTF2_CallbackCode
LocalLocationCb(void *                userData,
                OTF2_LocationRef      self,
                OTF2_StringRef        name,
                OTF2_LocationType     locationType,
                uint64_t              numberOfEvents,
                OTF2_LocationGroupRef locationGroup);

OTF2_CallbackCode
LocalRegionCb(void *          userData,
              OTF2_RegionRef  self,
              OTF2_StringRef  name,
              OTF2_StringRef  canonicalName,
              OTF2_StringRef  description,
              OTF2_RegionRole regionRole,
              OTF2_Paradigm   paradigm,
              OTF2_RegionFlag regionFlags,
              OTF2_StringRef  sourceFile,
              uint32_t        beginLineNumber,
              uint32_t        endLineNumber);

OTF2_CallbackCode
LocalCallsiteCb(void *           userData,
                OTF2_CallsiteRef self,
                OTF2_StringRef   sourceFile,
                uint32_t         lineNumber,
                OTF2_RegionRef   enteredRegion,
                OTF2_RegionRef   leftRegion);

OTF2_CallbackCode
LocalCallpathCb(void *userData, OTF2_CallpathRef self, OTF2_CallpathRef parent, OTF2_RegionRef region);

OTF2_CallbackCode
LocalGroupCb(void *          userData,
             OTF2_GroupRef   self,
             OTF2_StringRef  name,
             OTF2_GroupType  groupType,
             OTF2_Paradigm   paradigm,
             OTF2_GroupFlag  groupFlags,
             uint32_t        numberOfMembers,
             const uint64_t *members);

OTF2_CallbackCode
LocalMetricMemberCb(void *               userData,
                    OTF2_MetricMemberRef self,
                    OTF2_StringRef       name,
                    OTF2_StringRef       description,
                    OTF2_MetricType      metricType,
                    OTF2_MetricMode      metricMode,
                    OTF2_Type            valueType,
                    OTF2_Base            base,
                    int64_t              exponent,
                    OTF2_StringRef       unit);

OTF2_CallbackCode
LocalMetricClassCb(void *                      userData,
                   OTF2_MetricRef              self,
                   uint8_t                     numberOfMetrics,
                   const OTF2_MetricMemberRef *metricMembers,
                   OTF2_MetricOccurrence       metricOccurrence,
                   OTF2_RecorderKind           recorderKind);

OTF2_CallbackCode
LocalMetricInstanceCb(void *           userData,
                      OTF2_MetricRef   self,
                      OTF2_MetricRef   metricClass,
                      OTF2_LocationRef recorder,
                      OTF2_MetricScope metricScope,
                      uint64_t         scope);

OTF2_CallbackCode
LocalCommCb(void *userData, OTF2_CommRef self, OTF2_StringRef name, OTF2_GroupRef group, OTF2_CommRef parent);

OTF2_CallbackCode
LocalParameterCb(void *userData, OTF2_ParameterRef self, OTF2_StringRef name, OTF2_ParameterType parameterType);

OTF2_CallbackCode
LocalRmaWinCb(void *userData, OTF2_RmaWinRef self, OTF2_StringRef name, OTF2_CommRef comm);

OTF2_CallbackCode
LocalMetricClassRecorderCb(void *userData, OTF2_MetricRef metric, OTF2_LocationRef recorder);

OTF2_CallbackCode
LocalSystemTreeNodePropertyCb(void *                 userData,
                              OTF2_SystemTreeNodeRef systemTreeNode,
                              OTF2_StringRef         name,
                              OTF2_Type              type,
                              OTF2_AttributeValue    value);

OTF2_CallbackCode
LocalSystemTreeNodeDomainCb(void *                 userData,
                            OTF2_SystemTreeNodeRef systemTreeNode,
                            OTF2_SystemTreeDomain  systemTreeDomain);

OTF2_CallbackCode
LocalLocationGroupPropertyCb(void *                userData,
                             OTF2_LocationGroupRef locationGroup,
                             OTF2_StringRef        name,
                             OTF2_Type             type,
                             OTF2_AttributeValue   value);

OTF2_CallbackCode
LocalLocationPropertyCb(
    void *userData, OTF2_LocationRef location, OTF2_StringRef name, OTF2_Type type, OTF2_AttributeValue value);

OTF2_CallbackCode
LocalCartDimensionCb(void *                userData,
                     OTF2_CartDimensionRef self,
                     OTF2_StringRef        name,
                     uint32_t              size,
                     OTF2_CartPeriodicity  cartPeriodicity);

OTF2_CallbackCode
LocalCartTopologyCb(void *                       userData,
                    OTF2_CartTopologyRef         self,
                    OTF2_StringRef               name,
                    OTF2_CommRef                 communicator,
                    uint8_t                      numberOfDimensions,
                    const OTF2_CartDimensionRef *cartDimensions);

OTF2_CallbackCode
LocalCartCoordinateCb(void *               userData,
                      OTF2_CartTopologyRef cartTopology,
                      uint32_t             rank,
                      uint8_t              numberOfDimensions,
                      const uint32_t *     coordinates);

OTF2_CallbackCode
LocalSourceCodeLocationCb(void *userData, OTF2_SourceCodeLocationRef self, OTF2_StringRef file, uint32_t lineNumber);

OTF2_CallbackCode
LocalCallingContextCb(void *                     userData,
                      OTF2_CallingContextRef     self,
                      OTF2_RegionRef             region,
                      OTF2_SourceCodeLocationRef sourceCodeLocation,
                      OTF2_CallingContextRef     parent);

OTF2_CallbackCode
LocalCallingContextPropertyCb(void *                 userData,
                              OTF2_CallingContextRef callingContext,
                              OTF2_StringRef         name,
                              OTF2_Type              type,
                              OTF2_AttributeValue    value);

OTF2_CallbackCode
LocalInterruptGeneratorCb(void *                      userData,
                          OTF2_InterruptGeneratorRef  self,
                          OTF2_StringRef              name,
                          OTF2_InterruptGeneratorMode interruptGeneratorMode,
                          OTF2_Base                   base,
                          int64_t                     exponent,
                          uint64_t                    period);

OTF2_CallbackCode
LocalIoFilePropertyCb(
    void *userData, OTF2_IoFileRef ioFile, OTF2_StringRef name, OTF2_Type type, OTF2_AttributeValue value);

OTF2_CallbackCode
LocalIoRegularFileCb(void *userData, OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope);

OTF2_CallbackCode
LocalIoDirectoryCb(void *userData, OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope);

OTF2_CallbackCode
LocalIoHandleCb(void *             userData,
                OTF2_IoHandleRef   self,
                OTF2_StringRef     name,
                OTF2_IoFileRef     file,
                OTF2_IoParadigmRef ioParadigm,
                OTF2_IoHandleFlag  ioHandleFlags,
                OTF2_CommRef       comm,
                OTF2_IoHandleRef   parent);

OTF2_CallbackCode
LocalIoPreCreatedHandleStateCb(void *            userData,
                               OTF2_IoHandleRef  ioHandle,
                               OTF2_IoAccessMode mode,
                               OTF2_IoStatusFlag statusFlags);

OTF2_CallbackCode
LocalCallpathParameterCb(
    void *userData, OTF2_CallpathRef callpath, OTF2_ParameterRef parameter, OTF2_Type type, OTF2_AttributeValue value);

} // namespace definition
#endif /* EVENT_CALLBACKS_HPP */