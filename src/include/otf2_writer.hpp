#ifndef OTF2_WRITER_H
#define OTF2_WRITER_H

extern "C" {
#include <otf2/otf2.h>
}

class Otf2Writer {
  public:
    virtual void writeClockProperties(uint64_t timerResolution,
                                      uint64_t globalOffset,
                                      uint64_t traceLength) = 0;

    virtual void writeParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name,
                               OTF2_ParadigmClass paradigmClass) = 0;

    virtual void writeParadigmProperty(OTF2_Paradigm paradigm,
                                       OTF2_ParadigmProperty property,
                                       OTF2_Type type,
                                       OTF2_AttributeValue value) = 0;

    virtual void writeIoParadigm(
        OTF2_IoParadigmRef self, OTF2_StringRef identification,
        OTF2_StringRef name, OTF2_IoParadigmClass ioParadigmClass,
        OTF2_IoParadigmFlag ioParadigmFlags, uint8_t numberOfProperties,
        const OTF2_IoParadigmProperty *properties, const OTF2_Type *types,
        const OTF2_AttributeValue *values) = 0;

    virtual void writeString(OTF2_StringRef self, const char *string) = 0;

    virtual void writeAttribute(OTF2_AttributeRef self, OTF2_StringRef name,
                                OTF2_StringRef description, OTF2_Type type) = 0;

    virtual void writeSystemTreeNode(OTF2_SystemTreeNodeRef self,
                                     OTF2_StringRef name,
                                     OTF2_StringRef className,
                                     OTF2_SystemTreeNodeRef parent) = 0;

    virtual void
    writeLocationGroup(OTF2_LocationGroupRef self, OTF2_StringRef name,
                       OTF2_LocationGroupType locationGroupType,
                       OTF2_SystemTreeNodeRef systemTreeParent) = 0;

    virtual void writeLocation(OTF2_LocationRef self, OTF2_StringRef name,
                               OTF2_LocationType locationType,
                               uint64_t numberOfEvents,
                               OTF2_LocationGroupRef locationGroup) = 0;

    virtual void
    writeRegion(OTF2_RegionRef self, OTF2_StringRef name,
                OTF2_StringRef canonicalName, OTF2_StringRef description,
                OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
                uint32_t beginLineNumber, uint32_t endLineNumber) = 0;

    virtual void writeCallsite(OTF2_CallsiteRef self, OTF2_StringRef sourceFile,
                               uint32_t lineNumber,
                               OTF2_RegionRef enteredRegion,
                               OTF2_RegionRef leftRegion) = 0;

    virtual void writeCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent,
                               OTF2_RegionRef region) = 0;

    virtual void writeGroup(OTF2_GroupRef self, OTF2_StringRef name,
                            OTF2_GroupType groupType, OTF2_Paradigm paradigm,
                            OTF2_GroupFlag groupFlags, uint32_t numberOfMembers,
                            const uint64_t *members) = 0;

    virtual void writeMetricMember(OTF2_MetricMemberRef self,
                                   OTF2_StringRef name,
                                   OTF2_StringRef description,
                                   OTF2_MetricType metricType,
                                   OTF2_MetricMode metricMode,
                                   OTF2_Type valueType, OTF2_Base base,
                                   int64_t exponent, OTF2_StringRef unit) = 0;

    virtual void writeMetricClass(OTF2_MetricRef self, uint8_t numberOfMetrics,
                                  const OTF2_MetricMemberRef *metricMembers,
                                  OTF2_MetricOccurrence metricOccurrence,
                                  OTF2_RecorderKind recorderKind) = 0;

    virtual void writeMetricInstance(OTF2_MetricRef self,
                                     OTF2_MetricRef metricClass,
                                     OTF2_LocationRef recorder,
                                     OTF2_MetricScope metricScope,
                                     uint64_t scope) = 0;

    virtual void writeComm(OTF2_CommRef self, OTF2_StringRef name,
                           OTF2_GroupRef group, OTF2_CommRef parent) = 0;

    virtual void writeParameter(OTF2_ParameterRef self, OTF2_StringRef name,
                                OTF2_ParameterType parameterType) = 0;

    virtual void writeRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name,
                             OTF2_CommRef comm) = 0;

    virtual void writeMetricClassRecorder(OTF2_MetricRef metric,
                                          OTF2_LocationRef recorder) = 0;

    virtual void
    writeSystemTreeNodeProperty(OTF2_SystemTreeNodeRef systemTreeNode,
                                OTF2_StringRef name, OTF2_Type type,
                                OTF2_AttributeValue value) = 0;

    virtual void
    writeSystemTreeNodeDomain(OTF2_SystemTreeNodeRef systemTreeNode,
                              OTF2_SystemTreeDomain systemTreeDomain) = 0;

    virtual void writeLocationGroupProperty(OTF2_LocationGroupRef locationGroup,
                                            OTF2_StringRef name, OTF2_Type type,
                                            OTF2_AttributeValue value) = 0;

    virtual void writeLocationProperty(OTF2_LocationRef location,
                                       OTF2_StringRef name, OTF2_Type type,
                                       OTF2_AttributeValue value) = 0;

    virtual void writeCartDimension(OTF2_CartDimensionRef self,
                                    OTF2_StringRef name, uint32_t size,
                                    OTF2_CartPeriodicity cartPeriodicity) = 0;

    virtual void
    writeCartTopology(OTF2_CartTopologyRef self, OTF2_StringRef name,
                      OTF2_CommRef communicator, uint8_t numberOfDimensions,
                      const OTF2_CartDimensionRef *cartDimensions) = 0;

    virtual void writeCartCoordinate(OTF2_CartTopologyRef cartTopology,
                                     uint32_t rank, uint8_t numberOfDimensions,
                                     const uint32_t *coordinates) = 0;

    virtual void writeSourceCodeLocation(OTF2_SourceCodeLocationRef self,
                                         OTF2_StringRef file,
                                         uint32_t lineNumber) = 0;

    virtual void
    writeCallingContext(OTF2_CallingContextRef self, OTF2_RegionRef region,
                        OTF2_SourceCodeLocationRef sourceCodeLocation,
                        OTF2_CallingContextRef parent) = 0;

    virtual void
    writeCallingContextProperty(OTF2_CallingContextRef callingContext,
                                OTF2_StringRef name, OTF2_Type type,
                                OTF2_AttributeValue value) = 0;

    virtual void writeInterruptGenerator(
        OTF2_InterruptGeneratorRef self, OTF2_StringRef name,
        OTF2_InterruptGeneratorMode interruptGeneratorMode, OTF2_Base base,
        int64_t exponent, uint64_t period) = 0;

    virtual void writeIoFileProperty(OTF2_IoFileRef ioFile, OTF2_StringRef name,
                                     OTF2_Type type,
                                     OTF2_AttributeValue value) = 0;

    virtual void writeIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name,
                                    OTF2_SystemTreeNodeRef scope) = 0;

    virtual void writeIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name,
                                  OTF2_SystemTreeNodeRef scope) = 0;

    virtual void writeIoHandle(OTF2_IoHandleRef self, OTF2_StringRef name,
                               OTF2_IoFileRef file,
                               OTF2_IoParadigmRef ioParadigm,
                               OTF2_IoHandleFlag ioHandleFlags,
                               OTF2_CommRef comm, OTF2_IoHandleRef parent) = 0;

    virtual void
    writeIoPreCreatedHandleState(OTF2_IoHandleRef ioHandle,
                                 OTF2_IoAccessMode mode,
                                 OTF2_IoStatusFlag statusFlags) = 0;

    virtual void writeCallpathParameter(OTF2_CallpathRef callpath,
                                        OTF2_ParameterRef parameter,
                                        OTF2_Type type,
                                        OTF2_AttributeValue value) = 0;

    virtual void writeBufferFlushEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_TimeStamp stopTime) = 0;

    virtual void
    writeMeasurementOnOffEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                               OTF2_AttributeList *attributes,
                               OTF2_MeasurementMode measurementMode) = 0;

    virtual void writeEnterEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RegionRef region) = 0;

    virtual void writeLeaveEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RegionRef region) = 0;

    virtual void writeMpiSendEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t receiver, OTF2_CommRef communicator,
                                   uint32_t msgTag, uint64_t msgLength) = 0;

    virtual void writeMpiIsendEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t receiver,
                                    OTF2_CommRef communicator, uint32_t msgTag,
                                    uint64_t msgLength, uint64_t requestID) = 0;

    virtual void writeMpiIsendCompleteEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint64_t requestID) = 0;

    virtual void writeMpiIrecvRequestEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t requestID) = 0;

    virtual void writeMpiRecvEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t sender, OTF2_CommRef communicator,
                                   uint32_t msgTag, uint64_t msgLength) = 0;

    virtual void writeMpiIrecvEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t sender, OTF2_CommRef communicator,
                                    uint32_t msgTag, uint64_t msgLength,
                                    uint64_t requestID) = 0;

    virtual void writeMpiRequestTestEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint64_t requestID) = 0;

    virtual void writeMpiRequestCancelledEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               uint64_t requestID) = 0;

    virtual void
    writeMpiCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes) = 0;

    virtual void writeMpiCollectiveEndEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CollectiveOp collectiveOp,
                                            OTF2_CommRef communicator,
                                            uint32_t root, uint64_t sizeSent,
                                            uint64_t sizeReceived) = 0;

    virtual void writeOmpForkEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t numberOfRequestedThreads) = 0;

    virtual void writeOmpJoinEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes) = 0;

    virtual void writeOmpAcquireLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint32_t lockID,
                                          uint32_t acquisitionOrder) = 0;

    virtual void writeOmpReleaseLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint32_t lockID,
                                          uint32_t acquisitionOrder) = 0;

    virtual void writeOmpTaskCreateEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         uint64_t taskID) = 0;

    virtual void writeOmpTaskSwitchEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         uint64_t taskID) = 0;

    virtual void writeOmpTaskCompleteEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t taskID) = 0;

    virtual void
    writeMetricEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes, OTF2_MetricRef metric,
                     uint8_t numberOfMetrics, const OTF2_Type *typeIDs,
                     const OTF2_MetricValue *metricValues) = 0;

    virtual void writeParameterStringEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_ParameterRef parameter,
                                           OTF2_StringRef string) = 0;

    virtual void writeParameterIntEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_ParameterRef parameter,
                                        int64_t value) = 0;

    virtual void writeParameterUnsignedIntEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_ParameterRef parameter,
                                                uint64_t value) = 0;

    virtual void writeRmaWinCreateEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef win) = 0;

    virtual void writeRmaWinDestroyEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaWinRef win) = 0;

    virtual void
    writeRmaCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes) = 0;

    virtual void writeRmaCollectiveEndEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CollectiveOp collectiveOp,
        OTF2_RmaSyncLevel syncLevel, OTF2_RmaWinRef win, uint32_t root,
        uint64_t bytesSent, uint64_t bytesReceived) = 0;

    virtual void writeRmaGroupSyncEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaSyncLevel syncLevel,
                                        OTF2_RmaWinRef win,
                                        OTF2_GroupRef group) = 0;

    virtual void writeRmaRequestLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId,
                                          OTF2_LockType lockType) = 0;

    virtual void writeRmaAcquireLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId,
                                          OTF2_LockType lockType) = 0;

    virtual void writeRmaTryLockEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_RmaWinRef win, uint32_t remote,
                                      uint64_t lockId,
                                      OTF2_LockType lockType) = 0;

    virtual void writeRmaReleaseLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId) = 0;

    virtual void writeRmaSyncEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   OTF2_RmaSyncType syncType) = 0;

    virtual void writeRmaWaitChangeEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaWinRef win) = 0;

    virtual void writeRmaPutEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win, uint32_t remote,
                                  uint64_t bytes, uint64_t matchingId) = 0;

    virtual void writeRmaGetEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win, uint32_t remote,
                                  uint64_t bytes, uint64_t matchingId) = 0;

    virtual void writeRmaAtomicEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef win, uint32_t remote,
                                     OTF2_RmaAtomicType type,
                                     uint64_t bytesSent, uint64_t bytesReceived,
                                     uint64_t matchingId) = 0;

    virtual void writeRmaOpCompleteBlockingEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_RmaWinRef win,
                                                 uint64_t matchingId) = 0;

    virtual void writeRmaOpCompleteNonBlockingEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
        uint64_t matchingId) = 0;

    virtual void writeRmaOpTestEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef win,
                                     uint64_t matchingId) = 0;

    virtual void writeRmaOpCompleteRemoteEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_RmaWinRef win,
                                               uint64_t matchingId) = 0;

    virtual void writeThreadForkEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_Paradigm model,
                                      uint32_t numberOfRequestedThreads) = 0;

    virtual void writeThreadJoinEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_Paradigm model) = 0;

    virtual void writeThreadTeamBeginEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_CommRef threadTeam) = 0;

    virtual void writeThreadTeamEndEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_CommRef threadTeam) = 0;

    virtual void writeThreadAcquireLockEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_Paradigm model,
                                             uint32_t lockID,
                                             uint32_t acquisitionOrder) = 0;

    virtual void writeThreadReleaseLockEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_Paradigm model,
                                             uint32_t lockID,
                                             uint32_t acquisitionOrder) = 0;

    virtual void writeThreadTaskCreateEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CommRef threadTeam,
                                            uint32_t creatingThread,
                                            uint32_t generationNumber) = 0;

    virtual void writeThreadTaskSwitchEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CommRef threadTeam,
                                            uint32_t creatingThread,
                                            uint32_t generationNumber) = 0;

    virtual void writeThreadTaskCompleteEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              OTF2_CommRef threadTeam,
                                              uint32_t creatingThread,
                                              uint32_t generationNumber) = 0;

    virtual void writeThreadCreateEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CommRef threadContingent,
                                        uint64_t sequenceCount) = 0;

    virtual void writeThreadBeginEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_CommRef threadContingent,
                                       uint64_t sequenceCount) = 0;

    virtual void writeThreadWaitEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_CommRef threadContingent,
                                      uint64_t sequenceCount) = 0;

    virtual void writeThreadEndEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_CommRef threadContingent,
                                     uint64_t sequenceCount) = 0;

    virtual void writeCallingContextEnterEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance) = 0;

    virtual void
    writeCallingContextLeaveEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_CallingContextRef callingContext) = 0;

    virtual void writeCallingContextSampleEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance,
        OTF2_InterruptGeneratorRef interruptGenerator) = 0;

    virtual void writeIoCreateHandleEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_IoHandleRef handle,
                                          OTF2_IoAccessMode mode,
                                          OTF2_IoCreationFlag creationFlags,
                                          OTF2_IoStatusFlag statusFlags) = 0;

    virtual void writeIoDestroyHandleEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle) = 0;

    virtual void writeIoDuplicateHandleEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoHandleRef oldHandle,
                                             OTF2_IoHandleRef newHandle,
                                             OTF2_IoStatusFlag statusFlags) = 0;

    virtual void
    writeIoSeekEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                     int64_t offsetRequest, OTF2_IoSeekOption whence,
                     uint64_t offsetResult) = 0;

    virtual void writeIoChangeStatusFlagsEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoStatusFlag statusFlags) = 0;

    virtual void writeIoDeleteFileEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_IoParadigmRef ioParadigm,
                                        OTF2_IoFileRef file) = 0;

    virtual void writeIoOperationBeginEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
        uint64_t bytesRequest, uint64_t matchingId) = 0;

    virtual void writeIoOperationTestEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle,
                                           uint64_t matchingId) = 0;

    virtual void writeIoOperationIssuedEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoHandleRef handle,
                                             uint64_t matchingId) = 0;

    virtual void writeIoOperationCompleteEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_IoHandleRef handle,
                                               uint64_t bytesResult,
                                               uint64_t matchingId) = 0;

    virtual void writeIoOperationCancelledEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_IoHandleRef handle,
                                                uint64_t matchingId) = 0;

    virtual void writeIoAcquireLockEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         OTF2_LockType lockType) = 0;

    virtual void writeIoReleaseLockEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         OTF2_LockType lockType) = 0;

    virtual void writeIoTryLockEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_IoHandleRef handle,
                                     OTF2_LockType lockType) = 0;

    virtual void writeProgramBeginEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_StringRef programName,
        uint32_t numberOfArguments, const OTF2_StringRef *programArguments) = 0;

    virtual void writeProgramEndEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      int64_t exitStatus) = 0;
};

#endif /* OTF2_WRITER_H */