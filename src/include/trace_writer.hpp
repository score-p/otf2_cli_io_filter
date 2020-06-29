#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <functional>
#include <map>
#include <memory>
#include <string>

extern "C" {
#include <otf2/otf2.h>
}

#include "otf2_handler.hpp"

using archive_deleter = std::function<void(OTF2_Archive *)>;
using archive_ptr = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void(OTF2_EvtWriter *)>;
using event_writer_ptr = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

class TraceWriter : public Otf2Handler {
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    virtual ~TraceWriter();

    virtual void handleClockProperties(uint64_t timerResolution,
                                       uint64_t globalOffset,
                                       uint64_t traceLength) override;

    virtual void handleParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name,
                                OTF2_ParadigmClass paradigmClass) override;

    virtual void handleParadigmProperty(OTF2_Paradigm paradigm,
                                        OTF2_ParadigmProperty property,
                                        OTF2_Type type,
                                        OTF2_AttributeValue value) override;

    virtual void handleIoParadigm(
        OTF2_IoParadigmRef self, OTF2_StringRef identification,
        OTF2_StringRef name, OTF2_IoParadigmClass ioParadigmClass,
        OTF2_IoParadigmFlag ioParadigmFlags, uint8_t numberOfProperties,
        const OTF2_IoParadigmProperty *properties, const OTF2_Type *types,
        const OTF2_AttributeValue *values) override;

    virtual void handleString(OTF2_StringRef self, const char *string) override;

    virtual void handleAttribute(OTF2_AttributeRef self, OTF2_StringRef name,
                                 OTF2_StringRef description,
                                 OTF2_Type type) override;

    virtual void handleSystemTreeNode(OTF2_SystemTreeNodeRef self,
                                      OTF2_StringRef name,
                                      OTF2_StringRef className,
                                      OTF2_SystemTreeNodeRef parent) override;

    virtual void
    handleLocationGroup(OTF2_LocationGroupRef self, OTF2_StringRef name,
                        OTF2_LocationGroupType locationGroupType,
                        OTF2_SystemTreeNodeRef systemTreeParent) override;

    virtual void handleLocation(OTF2_LocationRef self, OTF2_StringRef name,
                                OTF2_LocationType locationType,
                                uint64_t numberOfEvents,
                                OTF2_LocationGroupRef locationGroup) override;

    virtual void
    handleRegion(OTF2_RegionRef self, OTF2_StringRef name,
                 OTF2_StringRef canonicalName, OTF2_StringRef description,
                 OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                 OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
                 uint32_t beginLineNumber, uint32_t endLineNumber) override;

    virtual void handleCallsite(OTF2_CallsiteRef self,
                                OTF2_StringRef sourceFile, uint32_t lineNumber,
                                OTF2_RegionRef enteredRegion,
                                OTF2_RegionRef leftRegion) override;

    virtual void handleCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent,
                                OTF2_RegionRef region) override;

    virtual void handleGroup(OTF2_GroupRef self, OTF2_StringRef name,
                             OTF2_GroupType groupType, OTF2_Paradigm paradigm,
                             OTF2_GroupFlag groupFlags,
                             uint32_t numberOfMembers,
                             const uint64_t *members) override;

    virtual void
    handleMetricMember(OTF2_MetricMemberRef self, OTF2_StringRef name,
                       OTF2_StringRef description, OTF2_MetricType metricType,
                       OTF2_MetricMode metricMode, OTF2_Type valueType,
                       OTF2_Base base, int64_t exponent,
                       OTF2_StringRef unit) override;

    virtual void handleMetricClass(OTF2_MetricRef self, uint8_t numberOfMetrics,
                                   const OTF2_MetricMemberRef *metricMembers,
                                   OTF2_MetricOccurrence metricOccurrence,
                                   OTF2_RecorderKind recorderKind) override;

    virtual void handleMetricInstance(OTF2_MetricRef self,
                                      OTF2_MetricRef metricClass,
                                      OTF2_LocationRef recorder,
                                      OTF2_MetricScope metricScope,
                                      uint64_t scope) override;

    virtual void handleComm(OTF2_CommRef self, OTF2_StringRef name,
                            OTF2_GroupRef group, OTF2_CommRef parent) override;

    virtual void handleParameter(OTF2_ParameterRef self, OTF2_StringRef name,
                                 OTF2_ParameterType parameterType) override;

    virtual void handleRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name,
                              OTF2_CommRef comm) override;

    virtual void handleMetricClassRecorder(OTF2_MetricRef metric,
                                           OTF2_LocationRef recorder) override;

    virtual void
    handleSystemTreeNodeProperty(OTF2_SystemTreeNodeRef systemTreeNode,
                                 OTF2_StringRef name, OTF2_Type type,
                                 OTF2_AttributeValue value) override;

    virtual void
    handleSystemTreeNodeDomain(OTF2_SystemTreeNodeRef systemTreeNode,
                               OTF2_SystemTreeDomain systemTreeDomain) override;

    virtual void
    handleLocationGroupProperty(OTF2_LocationGroupRef locationGroup,
                                OTF2_StringRef name, OTF2_Type type,
                                OTF2_AttributeValue value) override;

    virtual void handleLocationProperty(OTF2_LocationRef location,
                                        OTF2_StringRef name, OTF2_Type type,
                                        OTF2_AttributeValue value) override;

    virtual void
    handleCartDimension(OTF2_CartDimensionRef self, OTF2_StringRef name,
                        uint32_t size,
                        OTF2_CartPeriodicity cartPeriodicity) override;

    virtual void
    handleCartTopology(OTF2_CartTopologyRef self, OTF2_StringRef name,
                       OTF2_CommRef communicator, uint8_t numberOfDimensions,
                       const OTF2_CartDimensionRef *cartDimensions) override;

    virtual void handleCartCoordinate(OTF2_CartTopologyRef cartTopology,
                                      uint32_t rank, uint8_t numberOfDimensions,
                                      const uint32_t *coordinates) override;

    virtual void handleSourceCodeLocation(OTF2_SourceCodeLocationRef self,
                                          OTF2_StringRef file,
                                          uint32_t lineNumber) override;

    virtual void
    handleCallingContext(OTF2_CallingContextRef self, OTF2_RegionRef region,
                         OTF2_SourceCodeLocationRef sourceCodeLocation,
                         OTF2_CallingContextRef parent) override;

    virtual void
    handleCallingContextProperty(OTF2_CallingContextRef callingContext,
                                 OTF2_StringRef name, OTF2_Type type,
                                 OTF2_AttributeValue value) override;

    virtual void handleInterruptGenerator(
        OTF2_InterruptGeneratorRef self, OTF2_StringRef name,
        OTF2_InterruptGeneratorMode interruptGeneratorMode, OTF2_Base base,
        int64_t exponent, uint64_t period) override;

    virtual void handleIoFileProperty(OTF2_IoFileRef ioFile,
                                      OTF2_StringRef name, OTF2_Type type,
                                      OTF2_AttributeValue value) override;

    virtual void handleIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name,
                                     OTF2_SystemTreeNodeRef scope) override;

    virtual void handleIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name,
                                   OTF2_SystemTreeNodeRef scope) override;

    virtual void handleIoHandle(OTF2_IoHandleRef self, OTF2_StringRef name,
                                OTF2_IoFileRef file,
                                OTF2_IoParadigmRef ioParadigm,
                                OTF2_IoHandleFlag ioHandleFlags,
                                OTF2_CommRef comm,
                                OTF2_IoHandleRef parent) override;

    virtual void
    handleIoPreCreatedHandleState(OTF2_IoHandleRef ioHandle,
                                  OTF2_IoAccessMode mode,
                                  OTF2_IoStatusFlag statusFlags) override;

    virtual void handleCallpathParameter(OTF2_CallpathRef callpath,
                                         OTF2_ParameterRef parameter,
                                         OTF2_Type type,
                                         OTF2_AttributeValue value) override;

    virtual void handleBufferFlushEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_TimeStamp stopTime) override;

    virtual void
    handleMeasurementOnOffEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                OTF2_AttributeList *attributes,
                                OTF2_MeasurementMode measurementMode) override;

    virtual void handleEnterEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RegionRef region) override;

    virtual void handleLeaveEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RegionRef region) override;

    virtual void handleMpiSendEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t receiver,
                                    OTF2_CommRef communicator, uint32_t msgTag,
                                    uint64_t msgLength) override;

    virtual void
    handleMpiIsendEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                        OTF2_AttributeList *attributes, uint32_t receiver,
                        OTF2_CommRef communicator, uint32_t msgTag,
                        uint64_t msgLength, uint64_t requestID) override;

    virtual void handleMpiIsendCompleteEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             uint64_t requestID) override;

    virtual void handleMpiIrecvRequestEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint64_t requestID) override;

    virtual void handleMpiRecvEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t sender, OTF2_CommRef communicator,
                                    uint32_t msgTag,
                                    uint64_t msgLength) override;

    virtual void handleMpiIrecvEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     uint32_t sender, OTF2_CommRef communicator,
                                     uint32_t msgTag, uint64_t msgLength,
                                     uint64_t requestID) override;

    virtual void handleMpiRequestTestEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t requestID) override;

    virtual void handleMpiRequestCancelledEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                uint64_t requestID) override;

    virtual void
    handleMpiCollectiveBeginEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes) override;

    virtual void handleMpiCollectiveEndEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_CollectiveOp collectiveOp,
                                             OTF2_CommRef communicator,
                                             uint32_t root, uint64_t sizeSent,
                                             uint64_t sizeReceived) override;

    virtual void handleOmpForkEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t numberOfRequestedThreads) override;

    virtual void handleOmpJoinEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes) override;

    virtual void handleOmpAcquireLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint32_t lockID,
                                           uint32_t acquisitionOrder) override;

    virtual void handleOmpReleaseLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint32_t lockID,
                                           uint32_t acquisitionOrder) override;

    virtual void handleOmpTaskCreateEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint64_t taskID) override;

    virtual void handleOmpTaskSwitchEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint64_t taskID) override;

    virtual void handleOmpTaskCompleteEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint64_t taskID) override;

    virtual void
    handleMetricEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                      OTF2_AttributeList *attributes, OTF2_MetricRef metric,
                      uint8_t numberOfMetrics, const OTF2_Type *typeIDs,
                      const OTF2_MetricValue *metricValues) override;

    virtual void handleParameterStringEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_ParameterRef parameter,
                                            OTF2_StringRef string) override;

    virtual void handleParameterIntEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_ParameterRef parameter,
                                         int64_t value) override;

    virtual void handleParameterUnsignedIntEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_ParameterRef parameter,
                                                 uint64_t value) override;

    virtual void handleRmaWinCreateEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaWinRef win) override;

    virtual void handleRmaWinDestroyEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win) override;

    virtual void
    handleRmaCollectiveBeginEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes) override;

    virtual void handleRmaCollectiveEndEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CollectiveOp collectiveOp,
        OTF2_RmaSyncLevel syncLevel, OTF2_RmaWinRef win, uint32_t root,
        uint64_t bytesSent, uint64_t bytesReceived) override;

    virtual void handleRmaGroupSyncEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaSyncLevel syncLevel,
                                         OTF2_RmaWinRef win,
                                         OTF2_GroupRef group) override;

    virtual void handleRmaRequestLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_RmaWinRef win, uint32_t remote,
                                           uint64_t lockId,
                                           OTF2_LockType lockType) override;

    virtual void handleRmaAcquireLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_RmaWinRef win, uint32_t remote,
                                           uint64_t lockId,
                                           OTF2_LockType lockType) override;

    virtual void handleRmaTryLockEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_RmaWinRef win, uint32_t remote,
                                       uint64_t lockId,
                                       OTF2_LockType lockType) override;

    virtual void handleRmaReleaseLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_RmaWinRef win, uint32_t remote,
                                           uint64_t lockId) override;

    virtual void handleRmaSyncEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_RmaWinRef win, uint32_t remote,
                                    OTF2_RmaSyncType syncType) override;

    virtual void handleRmaWaitChangeEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win) override;

    virtual void handleRmaPutEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   uint64_t bytes,
                                   uint64_t matchingId) override;

    virtual void handleRmaGetEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   uint64_t bytes,
                                   uint64_t matchingId) override;

    virtual void
    handleRmaAtomicEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                         OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
                         uint32_t remote, OTF2_RmaAtomicType type,
                         uint64_t bytesSent, uint64_t bytesReceived,
                         uint64_t matchingId) override;

    virtual void handleRmaOpCompleteBlockingEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
        uint64_t matchingId) override;

    virtual void handleRmaOpCompleteNonBlockingEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
        uint64_t matchingId) override;

    virtual void handleRmaOpTestEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_RmaWinRef win,
                                      uint64_t matchingId) override;

    virtual void handleRmaOpCompleteRemoteEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_RmaWinRef win,
                                                uint64_t matchingId) override;

    virtual void
    handleThreadForkEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                          OTF2_AttributeList *attributes, OTF2_Paradigm model,
                          uint32_t numberOfRequestedThreads) override;

    virtual void handleThreadJoinEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_Paradigm model) override;

    virtual void handleThreadTeamBeginEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CommRef threadTeam) override;

    virtual void handleThreadTeamEndEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_CommRef threadTeam) override;

    virtual void
    handleThreadAcquireLockEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm model, uint32_t lockID,
                                 uint32_t acquisitionOrder) override;

    virtual void
    handleThreadReleaseLockEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm model, uint32_t lockID,
                                 uint32_t acquisitionOrder) override;

    virtual void handleThreadTaskCreateEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
        uint32_t creatingThread, uint32_t generationNumber) override;

    virtual void handleThreadTaskSwitchEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
        uint32_t creatingThread, uint32_t generationNumber) override;

    virtual void handleThreadTaskCompleteEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
        uint32_t creatingThread, uint32_t generationNumber) override;

    virtual void handleThreadCreateEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_CommRef threadContingent,
                                         uint64_t sequenceCount) override;

    virtual void handleThreadBeginEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CommRef threadContingent,
                                        uint64_t sequenceCount) override;

    virtual void handleThreadWaitEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_CommRef threadContingent,
                                       uint64_t sequenceCount) override;

    virtual void handleThreadEndEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_CommRef threadContingent,
                                      uint64_t sequenceCount) override;

    virtual void handleCallingContextEnterEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance) override;

    virtual void handleCallingContextLeaveEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes,
        OTF2_CallingContextRef callingContext) override;

    virtual void handleCallingContextSampleEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance,
        OTF2_InterruptGeneratorRef interruptGenerator) override;

    virtual void
    handleIoCreateHandleEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                              OTF2_AttributeList *attributes,
                              OTF2_IoHandleRef handle, OTF2_IoAccessMode mode,
                              OTF2_IoCreationFlag creationFlags,
                              OTF2_IoStatusFlag statusFlags) override;

    virtual void handleIoDestroyHandleEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_IoHandleRef handle) override;

    virtual void handleIoDuplicateHandleEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef oldHandle,
        OTF2_IoHandleRef newHandle, OTF2_IoStatusFlag statusFlags) override;

    virtual void
    handleIoSeekEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                      OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                      int64_t offsetRequest, OTF2_IoSeekOption whence,
                      uint64_t offsetResult) override;

    virtual void handleIoChangeStatusFlagsEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoStatusFlag statusFlags) override;

    virtual void handleIoDeleteFileEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoParadigmRef ioParadigm,
                                         OTF2_IoFileRef file) override;

    virtual void handleIoOperationBeginEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
        uint64_t bytesRequest, uint64_t matchingId) override;

    virtual void handleIoOperationTestEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_IoHandleRef handle,
                                            uint64_t matchingId) override;

    virtual void handleIoOperationIssuedEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              OTF2_IoHandleRef handle,
                                              uint64_t matchingId) override;

    virtual void handleIoOperationCompleteEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_IoHandleRef handle,
                                                uint64_t bytesResult,
                                                uint64_t matchingId) override;

    virtual void handleIoOperationCancelledEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_IoHandleRef handle,
                                                 uint64_t matchingId) override;

    virtual void handleIoAcquireLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_IoHandleRef handle,
                                          OTF2_LockType lockType) override;

    virtual void handleIoReleaseLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_IoHandleRef handle,
                                          OTF2_LockType lockType) override;

    virtual void handleIoTryLockEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_IoHandleRef handle,
                                      OTF2_LockType lockType) override;

    virtual void
    handleProgramBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                            OTF2_AttributeList *attributes,
                            OTF2_StringRef programName,
                            uint32_t numberOfArguments,
                            const OTF2_StringRef *programArguments) override;

    virtual void handleProgramEndEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       int64_t exitStatus) override;

  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    std::map<OTF2_LocationRef, event_writer_ptr> m_event_writer;
    OTF2_GlobalDefWriter *m_def_writer;
};

#endif /* TRACE_WRITER_H */