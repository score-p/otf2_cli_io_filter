#ifndef OTF2_HANDLER_H
#define OTF2_HANDLER_H

extern "C"
{
#include <otf2/otf2.h>
}

class Otf2Handler
{
  public:
    /*
     * Handle global definitions
     */

    virtual void
    handleGlobalClockProperties(uint64_t timerResolution, uint64_t globalOffset, uint64_t traceLength) = 0;

    virtual void
    handleGlobalParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name, OTF2_ParadigmClass paradigmClass) = 0;

    virtual void
    handleGlobalParadigmProperty(OTF2_Paradigm         paradigm,
                                 OTF2_ParadigmProperty property,
                                 OTF2_Type             type,
                                 OTF2_AttributeValue   value) = 0;

    virtual void
    handleGlobalIoParadigm(OTF2_IoParadigmRef             self,
                           OTF2_StringRef                 identification,
                           OTF2_StringRef                 name,
                           OTF2_IoParadigmClass           ioParadigmClass,
                           OTF2_IoParadigmFlag            ioParadigmFlags,
                           uint8_t                        numberOfProperties,
                           const OTF2_IoParadigmProperty *properties,
                           const OTF2_Type *              types,
                           const OTF2_AttributeValue *    values) = 0;

    virtual void
    handleGlobalString(OTF2_StringRef self, const char *string) = 0;

    virtual void
    handleGlobalAttribute(OTF2_AttributeRef self, OTF2_StringRef name, OTF2_StringRef description, OTF2_Type type) = 0;

    virtual void
    handleGlobalSystemTreeNode(OTF2_SystemTreeNodeRef self,
                               OTF2_StringRef         name,
                               OTF2_StringRef         className,
                               OTF2_SystemTreeNodeRef parent) = 0;

    virtual void
    handleGlobalLocationGroup(OTF2_LocationGroupRef  self,
                              OTF2_StringRef         name,
                              OTF2_LocationGroupType locationGroupType,
                              OTF2_SystemTreeNodeRef systemTreeParent) = 0;

    virtual void
    handleGlobalLocation(OTF2_LocationRef      self,
                         OTF2_StringRef        name,
                         OTF2_LocationType     locationType,
                         uint64_t              numberOfEvents,
                         OTF2_LocationGroupRef locationGroup) = 0;

    virtual void
    handleGlobalRegion(OTF2_RegionRef  self,
                       OTF2_StringRef  name,
                       OTF2_StringRef  canonicalName,
                       OTF2_StringRef  description,
                       OTF2_RegionRole regionRole,
                       OTF2_Paradigm   paradigm,
                       OTF2_RegionFlag regionFlags,
                       OTF2_StringRef  sourceFile,
                       uint32_t        beginLineNumber,
                       uint32_t        endLineNumber) = 0;

    virtual void
    handleGlobalCallsite(OTF2_CallsiteRef self,
                         OTF2_StringRef   sourceFile,
                         uint32_t         lineNumber,
                         OTF2_RegionRef   enteredRegion,
                         OTF2_RegionRef   leftRegion) = 0;

    virtual void
    handleGlobalCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent, OTF2_RegionRef region) = 0;

    virtual void
    handleGlobalGroup(OTF2_GroupRef   self,
                      OTF2_StringRef  name,
                      OTF2_GroupType  groupType,
                      OTF2_Paradigm   paradigm,
                      OTF2_GroupFlag  groupFlags,
                      uint32_t        numberOfMembers,
                      const uint64_t *members) = 0;

    virtual void
    handleGlobalMetricMember(OTF2_MetricMemberRef self,
                             OTF2_StringRef       name,
                             OTF2_StringRef       description,
                             OTF2_MetricType      metricType,
                             OTF2_MetricMode      metricMode,
                             OTF2_Type            valueType,
                             OTF2_Base            base,
                             int64_t              exponent,
                             OTF2_StringRef       unit) = 0;

    virtual void
    handleGlobalMetricClass(OTF2_MetricRef              self,
                            uint8_t                     numberOfMetrics,
                            const OTF2_MetricMemberRef *metricMembers,
                            OTF2_MetricOccurrence       metricOccurrence,
                            OTF2_RecorderKind           recorderKind) = 0;

    virtual void
    handleGlobalMetricInstance(OTF2_MetricRef   self,
                               OTF2_MetricRef   metricClass,
                               OTF2_LocationRef recorder,
                               OTF2_MetricScope metricScope,
                               uint64_t         scope) = 0;

    virtual void
    handleGlobalComm(OTF2_CommRef self, OTF2_StringRef name, OTF2_GroupRef group, OTF2_CommRef parent) = 0;

    virtual void
    handleGlobalParameter(OTF2_ParameterRef self, OTF2_StringRef name, OTF2_ParameterType parameterType) = 0;

    virtual void
    handleGlobalRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name, OTF2_CommRef comm) = 0;

    virtual void
    handleGlobalMetricClassRecorder(OTF2_MetricRef metric, OTF2_LocationRef recorder) = 0;

    virtual void
    handleGlobalSystemTreeNodeProperty(OTF2_SystemTreeNodeRef systemTreeNode,
                                       OTF2_StringRef         name,
                                       OTF2_Type              type,
                                       OTF2_AttributeValue    value) = 0;

    virtual void
    handleGlobalSystemTreeNodeDomain(OTF2_SystemTreeNodeRef systemTreeNode, OTF2_SystemTreeDomain systemTreeDomain) = 0;

    virtual void
    handleGlobalLocationGroupProperty(OTF2_LocationGroupRef locationGroup,
                                      OTF2_StringRef        name,
                                      OTF2_Type             type,
                                      OTF2_AttributeValue   value) = 0;

    virtual void
    handleGlobalLocationProperty(OTF2_LocationRef    location,
                                 OTF2_StringRef      name,
                                 OTF2_Type           type,
                                 OTF2_AttributeValue value) = 0;

    virtual void
    handleGlobalCartDimension(OTF2_CartDimensionRef self,
                              OTF2_StringRef        name,
                              uint32_t              size,
                              OTF2_CartPeriodicity  cartPeriodicity) = 0;

    virtual void
    handleGlobalCartTopology(OTF2_CartTopologyRef         self,
                             OTF2_StringRef               name,
                             OTF2_CommRef                 communicator,
                             uint8_t                      numberOfDimensions,
                             const OTF2_CartDimensionRef *cartDimensions) = 0;

    virtual void
    handleGlobalCartCoordinate(OTF2_CartTopologyRef cartTopology,
                               uint32_t             rank,
                               uint8_t              numberOfDimensions,
                               const uint32_t *     coordinates) = 0;

    virtual void
    handleGlobalSourceCodeLocation(OTF2_SourceCodeLocationRef self, OTF2_StringRef file, uint32_t lineNumber) = 0;

    virtual void
    handleGlobalCallingContext(OTF2_CallingContextRef     self,
                               OTF2_RegionRef             region,
                               OTF2_SourceCodeLocationRef sourceCodeLocation,
                               OTF2_CallingContextRef     parent) = 0;

    virtual void
    handleGlobalCallingContextProperty(OTF2_CallingContextRef callingContext,
                                       OTF2_StringRef         name,
                                       OTF2_Type              type,
                                       OTF2_AttributeValue    value) = 0;

    virtual void
    handleGlobalInterruptGenerator(OTF2_InterruptGeneratorRef  self,
                                   OTF2_StringRef              name,
                                   OTF2_InterruptGeneratorMode interruptGeneratorMode,
                                   OTF2_Base                   base,
                                   int64_t                     exponent,
                                   uint64_t                    period) = 0;

    virtual void
    handleGlobalIoFileProperty(OTF2_IoFileRef      ioFile,
                               OTF2_StringRef      name,
                               OTF2_Type           type,
                               OTF2_AttributeValue value) = 0;

    virtual void
    handleGlobalIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope) = 0;

    virtual void
    handleGlobalIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope) = 0;

    virtual void
    handleGlobalIoHandle(OTF2_IoHandleRef   self,
                         OTF2_StringRef     name,
                         OTF2_IoFileRef     file,
                         OTF2_IoParadigmRef ioParadigm,
                         OTF2_IoHandleFlag  ioHandleFlags,
                         OTF2_CommRef       comm,
                         OTF2_IoHandleRef   parent) = 0;

    virtual void
    handleGlobalIoPreCreatedHandleState(OTF2_IoHandleRef  ioHandle,
                                        OTF2_IoAccessMode mode,
                                        OTF2_IoStatusFlag statusFlags) = 0;

    virtual void
    handleGlobalCallpathParameter(OTF2_CallpathRef    callpath,
                                  OTF2_ParameterRef   parameter,
                                  OTF2_Type           type,
                                  OTF2_AttributeValue value) = 0;

    /*
     * Handle local definitions
     */

    virtual void
    handleLocalMappingTable(OTF2_LocationRef readLocation, OTF2_MappingType mappingType, const OTF2_IdMap *idMap) = 0;

    virtual void
    handleLocalClockOffset(OTF2_LocationRef readLocation,
                           OTF2_TimeStamp   time,
                           int64_t          offset,
                           double           standardDeviation) = 0;

    /*
     * Handle events.
     */

    virtual void
    handleBufferFlushEvent(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           OTF2_AttributeList *attributes,
                           OTF2_TimeStamp      stopTime) = 0;

    virtual void
    handleMeasurementOnOffEvent(OTF2_LocationRef     location,
                                OTF2_TimeStamp       time,
                                OTF2_AttributeList * attributes,
                                OTF2_MeasurementMode measurementMode) = 0;

    virtual void
    handleEnterEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) = 0;

    virtual void
    handleLeaveEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) = 0;

    virtual void
    handleMpiSendEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            receiver,
                       OTF2_CommRef        communicator,
                       uint32_t            msgTag,
                       uint64_t            msgLength) = 0;

    virtual void
    handleMpiIsendEvent(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        OTF2_AttributeList *attributes,
                        uint32_t            receiver,
                        OTF2_CommRef        communicator,
                        uint32_t            msgTag,
                        uint64_t            msgLength,
                        uint64_t            requestID) = 0;

    virtual void
    handleMpiIsendCompleteEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                uint64_t            requestID) = 0;

    virtual void
    handleMpiIrecvRequestEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               uint64_t            requestID) = 0;

    virtual void
    handleMpiRecvEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            sender,
                       OTF2_CommRef        communicator,
                       uint32_t            msgTag,
                       uint64_t            msgLength) = 0;

    virtual void
    handleMpiIrecvEvent(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        OTF2_AttributeList *attributes,
                        uint32_t            sender,
                        OTF2_CommRef        communicator,
                        uint32_t            msgTag,
                        uint64_t            msgLength,
                        uint64_t            requestID) = 0;

    virtual void
    handleMpiRequestTestEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint64_t            requestID) = 0;

    virtual void
    handleMpiRequestCancelledEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   uint64_t            requestID) = 0;

    virtual void
    handleMpiCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time, OTF2_AttributeList *attributes) = 0;

    virtual void
    handleMpiCollectiveEndEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CollectiveOp   collectiveOp,
                                OTF2_CommRef        communicator,
                                uint32_t            root,
                                uint64_t            sizeSent,
                                uint64_t            sizeReceived) = 0;

    virtual void
    handleOmpForkEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            numberOfRequestedThreads) = 0;

    virtual void
    handleOmpJoinEvent(OTF2_LocationRef location, OTF2_TimeStamp time, OTF2_AttributeList *attributes) = 0;

    virtual void
    handleOmpAcquireLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint32_t            lockID,
                              uint32_t            acquisitionOrder) = 0;

    virtual void
    handleOmpReleaseLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint32_t            lockID,
                              uint32_t            acquisitionOrder) = 0;

    virtual void
    handleOmpTaskCreateEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             uint64_t            taskID) = 0;

    virtual void
    handleOmpTaskSwitchEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             uint64_t            taskID) = 0;

    virtual void
    handleOmpTaskCompleteEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               uint64_t            taskID) = 0;

    virtual void
    handleMetricEvent(OTF2_LocationRef        location,
                      OTF2_TimeStamp          time,
                      OTF2_AttributeList *    attributes,
                      OTF2_MetricRef          metric,
                      uint8_t                 numberOfMetrics,
                      const OTF2_Type *       typeIDs,
                      const OTF2_MetricValue *metricValues) = 0;

    virtual void
    handleParameterStringEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_ParameterRef   parameter,
                               OTF2_StringRef      string) = 0;

    virtual void
    handleParameterIntEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_ParameterRef   parameter,
                            int64_t             value) = 0;

    virtual void
    handleParameterUnsignedIntEvent(OTF2_LocationRef    location,
                                    OTF2_TimeStamp      time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_ParameterRef   parameter,
                                    uint64_t            value) = 0;

    virtual void
    handleRmaWinCreateEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_RmaWinRef      win) = 0;

    virtual void
    handleRmaWinDestroyEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win) = 0;

    virtual void
    handleRmaCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time, OTF2_AttributeList *attributes) = 0;

    virtual void
    handleRmaCollectiveEndEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CollectiveOp   collectiveOp,
                                OTF2_RmaSyncLevel   syncLevel,
                                OTF2_RmaWinRef      win,
                                uint32_t            root,
                                uint64_t            bytesSent,
                                uint64_t            bytesReceived) = 0;

    virtual void
    handleRmaGroupSyncEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_RmaSyncLevel   syncLevel,
                            OTF2_RmaWinRef      win,
                            OTF2_GroupRef       group) = 0;

    virtual void
    handleRmaRequestLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId,
                              OTF2_LockType       lockType) = 0;

    virtual void
    handleRmaAcquireLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId,
                              OTF2_LockType       lockType) = 0;

    virtual void
    handleRmaTryLockEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_RmaWinRef      win,
                          uint32_t            remote,
                          uint64_t            lockId,
                          OTF2_LockType       lockType) = 0;

    virtual void
    handleRmaReleaseLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId) = 0;

    virtual void
    handleRmaSyncEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       OTF2_RmaWinRef      win,
                       uint32_t            remote,
                       OTF2_RmaSyncType    syncType) = 0;

    virtual void
    handleRmaWaitChangeEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win) = 0;

    virtual void
    handleRmaPutEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            bytes,
                      uint64_t            matchingId) = 0;

    virtual void
    handleRmaGetEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            bytes,
                      uint64_t            matchingId) = 0;

    virtual void
    handleRmaAtomicEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_RmaWinRef      win,
                         uint32_t            remote,
                         OTF2_RmaAtomicType  type,
                         uint64_t            bytesSent,
                         uint64_t            bytesReceived,
                         uint64_t            matchingId) = 0;

    virtual void
    handleRmaOpCompleteBlockingEvent(OTF2_LocationRef    location,
                                     OTF2_TimeStamp      time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef      win,
                                     uint64_t            matchingId) = 0;

    virtual void
    handleRmaOpCompleteNonBlockingEvent(OTF2_LocationRef    location,
                                        OTF2_TimeStamp      time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef      win,
                                        uint64_t            matchingId) = 0;

    virtual void
    handleRmaOpTestEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_RmaWinRef      win,
                         uint64_t            matchingId) = 0;

    virtual void
    handleRmaOpCompleteRemoteEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef      win,
                                   uint64_t            matchingId) = 0;

    virtual void
    handleThreadForkEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_Paradigm       model,
                          uint32_t            numberOfRequestedThreads) = 0;

    virtual void
    handleThreadJoinEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_Paradigm       model) = 0;

    virtual void
    handleThreadTeamBeginEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_CommRef        threadTeam) = 0;

    virtual void
    handleThreadTeamEndEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_CommRef        threadTeam) = 0;

    virtual void
    handleThreadAcquireLockEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm       model,
                                 uint32_t            lockID,
                                 uint32_t            acquisitionOrder) = 0;

    virtual void
    handleThreadReleaseLockEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm       model,
                                 uint32_t            lockID,
                                 uint32_t            acquisitionOrder) = 0;

    virtual void
    handleThreadTaskCreateEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CommRef        threadTeam,
                                uint32_t            creatingThread,
                                uint32_t            generationNumber) = 0;

    virtual void
    handleThreadTaskSwitchEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CommRef        threadTeam,
                                uint32_t            creatingThread,
                                uint32_t            generationNumber) = 0;

    virtual void
    handleThreadTaskCompleteEvent(OTF2_LocationRef    location,
                                  OTF2_TimeStamp      time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_CommRef        threadTeam,
                                  uint32_t            creatingThread,
                                  uint32_t            generationNumber) = 0;

    virtual void
    handleThreadCreateEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_CommRef        threadContingent,
                            uint64_t            sequenceCount) = 0;

    virtual void
    handleThreadBeginEvent(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           OTF2_AttributeList *attributes,
                           OTF2_CommRef        threadContingent,
                           uint64_t            sequenceCount) = 0;

    virtual void
    handleThreadWaitEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_CommRef        threadContingent,
                          uint64_t            sequenceCount) = 0;

    virtual void
    handleThreadEndEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_CommRef        threadContingent,
                         uint64_t            sequenceCount) = 0;

    virtual void
    handleCallingContextEnterEvent(OTF2_LocationRef       location,
                                   OTF2_TimeStamp         time,
                                   OTF2_AttributeList *   attributes,
                                   OTF2_CallingContextRef callingContext,
                                   uint32_t               unwindDistance) = 0;

    virtual void
    handleCallingContextLeaveEvent(OTF2_LocationRef       location,
                                   OTF2_TimeStamp         time,
                                   OTF2_AttributeList *   attributes,
                                   OTF2_CallingContextRef callingContext) = 0;

    virtual void
    handleCallingContextSampleEvent(OTF2_LocationRef           location,
                                    OTF2_TimeStamp             time,
                                    OTF2_AttributeList *       attributes,
                                    OTF2_CallingContextRef     callingContext,
                                    uint32_t                   unwindDistance,
                                    OTF2_InterruptGeneratorRef interruptGenerator) = 0;

    virtual void
    handleIoCreateHandleEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_IoHandleRef    handle,
                              OTF2_IoAccessMode   mode,
                              OTF2_IoCreationFlag creationFlags,
                              OTF2_IoStatusFlag   statusFlags) = 0;

    virtual void
    handleIoDestroyHandleEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_IoHandleRef    handle) = 0;

    virtual void
    handleIoDuplicateHandleEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_IoHandleRef    oldHandle,
                                 OTF2_IoHandleRef    newHandle,
                                 OTF2_IoStatusFlag   statusFlags) = 0;

    virtual void
    handleIoSeekEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_IoHandleRef    handle,
                      int64_t             offsetRequest,
                      OTF2_IoSeekOption   whence,
                      uint64_t            offsetResult) = 0;

    virtual void
    handleIoChangeStatusFlagsEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_IoHandleRef    handle,
                                   OTF2_IoStatusFlag   statusFlags) = 0;

    virtual void
    handleIoDeleteFileEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_IoParadigmRef  ioParadigm,
                            OTF2_IoFileRef      file) = 0;

    virtual void
    handleIoOperationBeginEvent(OTF2_LocationRef     location,
                                OTF2_TimeStamp       time,
                                OTF2_AttributeList * attributes,
                                OTF2_IoHandleRef     handle,
                                OTF2_IoOperationMode mode,
                                OTF2_IoOperationFlag operationFlags,
                                uint64_t             bytesRequest,
                                uint64_t             matchingId) = 0;

    virtual void
    handleIoOperationTestEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_IoHandleRef    handle,
                               uint64_t            matchingId) = 0;

    virtual void
    handleIoOperationIssuedEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_IoHandleRef    handle,
                                 uint64_t            matchingId) = 0;

    virtual void
    handleIoOperationCompleteEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_IoHandleRef    handle,
                                   uint64_t            bytesResult,
                                   uint64_t            matchingId) = 0;

    virtual void
    handleIoOperationCancelledEvent(OTF2_LocationRef    location,
                                    OTF2_TimeStamp      time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_IoHandleRef    handle,
                                    uint64_t            matchingId) = 0;

    virtual void
    handleIoAcquireLockEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_IoHandleRef    handle,
                             OTF2_LockType       lockType) = 0;

    virtual void
    handleIoReleaseLockEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_IoHandleRef    handle,
                             OTF2_LockType       lockType) = 0;

    virtual void
    handleIoTryLockEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    handle,
                         OTF2_LockType       lockType) = 0;

    virtual void
    handleProgramBeginEvent(OTF2_LocationRef      location,
                            OTF2_TimeStamp        time,
                            OTF2_AttributeList *  attributes,
                            OTF2_StringRef        programName,
                            uint32_t              numberOfArguments,
                            const OTF2_StringRef *programArguments) = 0;

    virtual void
    handleProgramEndEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          int64_t             exitStatus) = 0;
};

#endif /* OTF2_HANDLER_H */