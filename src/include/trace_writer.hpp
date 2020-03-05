#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <functional>
#include <map>
#include <memory>
#include <string>

extern "C" {
#include <otf2/otf2.h>
}

#include "otf2_writer.hpp"

using archive_deleter = std::function<void(OTF2_Archive *)>;
using archive_ptr = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void(OTF2_EvtWriter *)>;
using event_writer_ptr = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

class TraceWriter : public Otf2Writer {
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    virtual ~TraceWriter();

    virtual void writeClockProperties(uint64_t timerResolution,
                                      uint64_t globalOffset,
                                      uint64_t traceLength) override;

    virtual void writeParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name,
                               OTF2_ParadigmClass paradigmClass) override;

    virtual void writeParadigmProperty(OTF2_Paradigm paradigm,
                                       OTF2_ParadigmProperty property,
                                       OTF2_Type type,
                                       OTF2_AttributeValue value) override;

    virtual void writeIoParadigm(
        OTF2_IoParadigmRef self, OTF2_StringRef identification,
        OTF2_StringRef name, OTF2_IoParadigmClass ioParadigmClass,
        OTF2_IoParadigmFlag ioParadigmFlags, uint8_t numberOfProperties,
        const OTF2_IoParadigmProperty *properties, const OTF2_Type *types,
        const OTF2_AttributeValue *values) override;

    virtual void writeString(OTF2_StringRef self, const char *string) override;

    virtual void writeAttribute(OTF2_AttributeRef self, OTF2_StringRef name,
                                OTF2_StringRef description,
                                OTF2_Type type) override;

    virtual void writeSystemTreeNode(OTF2_SystemTreeNodeRef self,
                                     OTF2_StringRef name,
                                     OTF2_StringRef className,
                                     OTF2_SystemTreeNodeRef parent) override;

    virtual void
    writeLocationGroup(OTF2_LocationGroupRef self, OTF2_StringRef name,
                       OTF2_LocationGroupType locationGroupType,
                       OTF2_SystemTreeNodeRef systemTreeParent) override;

    virtual void writeLocation(OTF2_LocationRef self, OTF2_StringRef name,
                               OTF2_LocationType locationType,
                               uint64_t numberOfEvents,
                               OTF2_LocationGroupRef locationGroup) override;

    virtual void
    writeRegion(OTF2_RegionRef self, OTF2_StringRef name,
                OTF2_StringRef canonicalName, OTF2_StringRef description,
                OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
                uint32_t beginLineNumber, uint32_t endLineNumber) override;

    virtual void writeCallsite(OTF2_CallsiteRef self, OTF2_StringRef sourceFile,
                               uint32_t lineNumber,
                               OTF2_RegionRef enteredRegion,
                               OTF2_RegionRef leftRegion) override;

    virtual void writeCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent,
                               OTF2_RegionRef region) override;

    virtual void writeGroup(OTF2_GroupRef self, OTF2_StringRef name,
                            OTF2_GroupType groupType, OTF2_Paradigm paradigm,
                            OTF2_GroupFlag groupFlags, uint32_t numberOfMembers,
                            const uint64_t *members) override;

    virtual void
    writeMetricMember(OTF2_MetricMemberRef self, OTF2_StringRef name,
                      OTF2_StringRef description, OTF2_MetricType metricType,
                      OTF2_MetricMode metricMode, OTF2_Type valueType,
                      OTF2_Base base, int64_t exponent,
                      OTF2_StringRef unit) override;

    virtual void writeMetricClass(OTF2_MetricRef self, uint8_t numberOfMetrics,
                                  const OTF2_MetricMemberRef *metricMembers,
                                  OTF2_MetricOccurrence metricOccurrence,
                                  OTF2_RecorderKind recorderKind) override;

    virtual void writeMetricInstance(OTF2_MetricRef self,
                                     OTF2_MetricRef metricClass,
                                     OTF2_LocationRef recorder,
                                     OTF2_MetricScope metricScope,
                                     uint64_t scope) override;

    virtual void writeComm(OTF2_CommRef self, OTF2_StringRef name,
                           OTF2_GroupRef group, OTF2_CommRef parent) override;

    virtual void writeParameter(OTF2_ParameterRef self, OTF2_StringRef name,
                                OTF2_ParameterType parameterType) override;

    virtual void writeRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name,
                             OTF2_CommRef comm) override;

    virtual void writeMetricClassRecorder(OTF2_MetricRef metric,
                                          OTF2_LocationRef recorder) override;

    virtual void
    writeSystemTreeNodeProperty(OTF2_SystemTreeNodeRef systemTreeNode,
                                OTF2_StringRef name, OTF2_Type type,
                                OTF2_AttributeValue value) override;

    virtual void
    writeSystemTreeNodeDomain(OTF2_SystemTreeNodeRef systemTreeNode,
                              OTF2_SystemTreeDomain systemTreeDomain) override;

    virtual void writeLocationGroupProperty(OTF2_LocationGroupRef locationGroup,
                                            OTF2_StringRef name, OTF2_Type type,
                                            OTF2_AttributeValue value) override;

    virtual void writeLocationProperty(OTF2_LocationRef location,
                                       OTF2_StringRef name, OTF2_Type type,
                                       OTF2_AttributeValue value) override;

    virtual void
    writeCartDimension(OTF2_CartDimensionRef self, OTF2_StringRef name,
                       uint32_t size,
                       OTF2_CartPeriodicity cartPeriodicity) override;

    virtual void
    writeCartTopology(OTF2_CartTopologyRef self, OTF2_StringRef name,
                      OTF2_CommRef communicator, uint8_t numberOfDimensions,
                      const OTF2_CartDimensionRef *cartDimensions) override;

    virtual void writeCartCoordinate(OTF2_CartTopologyRef cartTopology,
                                     uint32_t rank, uint8_t numberOfDimensions,
                                     const uint32_t *coordinates) override;

    virtual void writeSourceCodeLocation(OTF2_SourceCodeLocationRef self,
                                         OTF2_StringRef file,
                                         uint32_t lineNumber) override;

    virtual void
    writeCallingContext(OTF2_CallingContextRef self, OTF2_RegionRef region,
                        OTF2_SourceCodeLocationRef sourceCodeLocation,
                        OTF2_CallingContextRef parent) override;

    virtual void
    writeCallingContextProperty(OTF2_CallingContextRef callingContext,
                                OTF2_StringRef name, OTF2_Type type,
                                OTF2_AttributeValue value) override;

    virtual void writeInterruptGenerator(
        OTF2_InterruptGeneratorRef self, OTF2_StringRef name,
        OTF2_InterruptGeneratorMode interruptGeneratorMode, OTF2_Base base,
        int64_t exponent, uint64_t period) override;

    virtual void writeIoFileProperty(OTF2_IoFileRef ioFile, OTF2_StringRef name,
                                     OTF2_Type type,
                                     OTF2_AttributeValue value) override;

    virtual void writeIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name,
                                    OTF2_SystemTreeNodeRef scope) override;

    virtual void writeIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name,
                                  OTF2_SystemTreeNodeRef scope) override;

    virtual void writeIoHandle(OTF2_IoHandleRef self, OTF2_StringRef name,
                               OTF2_IoFileRef file,
                               OTF2_IoParadigmRef ioParadigm,
                               OTF2_IoHandleFlag ioHandleFlags,
                               OTF2_CommRef comm,
                               OTF2_IoHandleRef parent) override;

    virtual void
    writeIoPreCreatedHandleState(OTF2_IoHandleRef ioHandle,
                                 OTF2_IoAccessMode mode,
                                 OTF2_IoStatusFlag statusFlags) override;

    virtual void writeCallpathParameter(OTF2_CallpathRef callpath,
                                        OTF2_ParameterRef parameter,
                                        OTF2_Type type,
                                        OTF2_AttributeValue value) override;

    virtual void writeBufferFlushEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_TimeStamp stopTime) override;

    virtual void
    writeMeasurementOnOffEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                               OTF2_AttributeList *attributes,
                               OTF2_MeasurementMode measurementMode) override;

    virtual void writeEnterEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RegionRef region) override;

    virtual void writeLeaveEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_RegionRef region) override;

    virtual void writeMpiSendEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t receiver, OTF2_CommRef communicator,
                                   uint32_t msgTag,
                                   uint64_t msgLength) override;

    virtual void
    writeMpiIsendEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                       OTF2_AttributeList *attributes, uint32_t receiver,
                       OTF2_CommRef communicator, uint32_t msgTag,
                       uint64_t msgLength, uint64_t requestID) override;

    virtual void writeMpiIsendCompleteEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint64_t requestID) override;

    virtual void writeMpiIrecvRequestEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t requestID) override;

    virtual void writeMpiRecvEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t sender, OTF2_CommRef communicator,
                                   uint32_t msgTag,
                                   uint64_t msgLength) override;

    virtual void writeMpiIrecvEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    uint32_t sender, OTF2_CommRef communicator,
                                    uint32_t msgTag, uint64_t msgLength,
                                    uint64_t requestID) override;

    virtual void writeMpiRequestTestEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint64_t requestID) override;

    virtual void writeMpiRequestCancelledEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               uint64_t requestID) override;

    virtual void
    writeMpiCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes) override;

    virtual void writeMpiCollectiveEndEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CollectiveOp collectiveOp,
                                            OTF2_CommRef communicator,
                                            uint32_t root, uint64_t sizeSent,
                                            uint64_t sizeReceived) override;

    virtual void writeOmpForkEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   uint32_t numberOfRequestedThreads) override;

    virtual void writeOmpJoinEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes) override;

    virtual void writeOmpAcquireLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint32_t lockID,
                                          uint32_t acquisitionOrder) override;

    virtual void writeOmpReleaseLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          uint32_t lockID,
                                          uint32_t acquisitionOrder) override;

    virtual void writeOmpTaskCreateEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         uint64_t taskID) override;

    virtual void writeOmpTaskSwitchEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         uint64_t taskID) override;

    virtual void writeOmpTaskCompleteEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t taskID) override;

    virtual void
    writeMetricEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes, OTF2_MetricRef metric,
                     uint8_t numberOfMetrics, const OTF2_Type *typeIDs,
                     const OTF2_MetricValue *metricValues) override;

    virtual void writeParameterStringEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_ParameterRef parameter,
                                           OTF2_StringRef string) override;

    virtual void writeParameterIntEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_ParameterRef parameter,
                                        int64_t value) override;

    virtual void writeParameterUnsignedIntEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_ParameterRef parameter,
                                                uint64_t value) override;

    virtual void writeRmaWinCreateEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef win) override;

    virtual void writeRmaWinDestroyEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaWinRef win) override;

    virtual void
    writeRmaCollectiveBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                 OTF2_AttributeList *attributes) override;

    virtual void writeRmaCollectiveEndEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CollectiveOp collectiveOp,
        OTF2_RmaSyncLevel syncLevel, OTF2_RmaWinRef win, uint32_t root,
        uint64_t bytesSent, uint64_t bytesReceived) override;

    virtual void writeRmaGroupSyncEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaSyncLevel syncLevel,
                                        OTF2_RmaWinRef win,
                                        OTF2_GroupRef group) override;

    virtual void writeRmaRequestLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId,
                                          OTF2_LockType lockType) override;

    virtual void writeRmaAcquireLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId,
                                          OTF2_LockType lockType) override;

    virtual void writeRmaTryLockEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_RmaWinRef win, uint32_t remote,
                                      uint64_t lockId,
                                      OTF2_LockType lockType) override;

    virtual void writeRmaReleaseLockEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win, uint32_t remote,
                                          uint64_t lockId) override;

    virtual void writeRmaSyncEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef win, uint32_t remote,
                                   OTF2_RmaSyncType syncType) override;

    virtual void writeRmaWaitChangeEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_RmaWinRef win) override;

    virtual void writeRmaPutEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win, uint32_t remote,
                                  uint64_t bytes, uint64_t matchingId) override;

    virtual void writeRmaGetEvent(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RmaWinRef win, uint32_t remote,
                                  uint64_t bytes, uint64_t matchingId) override;

    virtual void writeRmaAtomicEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef win, uint32_t remote,
                                     OTF2_RmaAtomicType type,
                                     uint64_t bytesSent, uint64_t bytesReceived,
                                     uint64_t matchingId) override;

    virtual void writeRmaOpCompleteBlockingEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_RmaWinRef win,
                                                 uint64_t matchingId) override;

    virtual void writeRmaOpCompleteNonBlockingEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_RmaWinRef win,
        uint64_t matchingId) override;

    virtual void writeRmaOpTestEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef win,
                                     uint64_t matchingId) override;

    virtual void writeRmaOpCompleteRemoteEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_RmaWinRef win,
                                               uint64_t matchingId) override;

    virtual void
    writeThreadForkEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                         OTF2_AttributeList *attributes, OTF2_Paradigm model,
                         uint32_t numberOfRequestedThreads) override;

    virtual void writeThreadJoinEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_Paradigm model) override;

    virtual void writeThreadTeamBeginEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_CommRef threadTeam) override;

    virtual void writeThreadTeamEndEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_CommRef threadTeam) override;

    virtual void
    writeThreadAcquireLockEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                OTF2_AttributeList *attributes,
                                OTF2_Paradigm model, uint32_t lockID,
                                uint32_t acquisitionOrder) override;

    virtual void
    writeThreadReleaseLockEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                                OTF2_AttributeList *attributes,
                                OTF2_Paradigm model, uint32_t lockID,
                                uint32_t acquisitionOrder) override;

    virtual void writeThreadTaskCreateEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CommRef threadTeam,
                                            uint32_t creatingThread,
                                            uint32_t generationNumber) override;

    virtual void writeThreadTaskSwitchEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_CommRef threadTeam,
                                            uint32_t creatingThread,
                                            uint32_t generationNumber) override;

    virtual void writeThreadTaskCompleteEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CommRef threadTeam,
        uint32_t creatingThread, uint32_t generationNumber) override;

    virtual void writeThreadCreateEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CommRef threadContingent,
                                        uint64_t sequenceCount) override;

    virtual void writeThreadBeginEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_CommRef threadContingent,
                                       uint64_t sequenceCount) override;

    virtual void writeThreadWaitEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      OTF2_CommRef threadContingent,
                                      uint64_t sequenceCount) override;

    virtual void writeThreadEndEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_CommRef threadContingent,
                                     uint64_t sequenceCount) override;

    virtual void writeCallingContextEnterEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance) override;

    virtual void writeCallingContextLeaveEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes,
        OTF2_CallingContextRef callingContext) override;

    virtual void writeCallingContextSampleEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
        uint32_t unwindDistance,
        OTF2_InterruptGeneratorRef interruptGenerator) override;

    virtual void
    writeIoCreateHandleEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                             OTF2_AttributeList *attributes,
                             OTF2_IoHandleRef handle, OTF2_IoAccessMode mode,
                             OTF2_IoCreationFlag creationFlags,
                             OTF2_IoStatusFlag statusFlags) override;

    virtual void writeIoDestroyHandleEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle) override;

    virtual void writeIoDuplicateHandleEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef oldHandle,
        OTF2_IoHandleRef newHandle, OTF2_IoStatusFlag statusFlags) override;

    virtual void
    writeIoSeekEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
                     int64_t offsetRequest, OTF2_IoSeekOption whence,
                     uint64_t offsetResult) override;

    virtual void writeIoChangeStatusFlagsEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoStatusFlag statusFlags) override;

    virtual void writeIoDeleteFileEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_IoParadigmRef ioParadigm,
                                        OTF2_IoFileRef file) override;

    virtual void writeIoOperationBeginEvent(
        OTF2_LocationRef location, OTF2_TimeStamp time,
        OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
        OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
        uint64_t bytesRequest, uint64_t matchingId) override;

    virtual void writeIoOperationTestEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle,
                                           uint64_t matchingId) override;

    virtual void writeIoOperationIssuedEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoHandleRef handle,
                                             uint64_t matchingId) override;

    virtual void writeIoOperationCompleteEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_IoHandleRef handle,
                                               uint64_t bytesResult,
                                               uint64_t matchingId) override;

    virtual void writeIoOperationCancelledEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_IoHandleRef handle,
                                                uint64_t matchingId) override;

    virtual void writeIoAcquireLockEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         OTF2_LockType lockType) override;

    virtual void writeIoReleaseLockEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_IoHandleRef handle,
                                         OTF2_LockType lockType) override;

    virtual void writeIoTryLockEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_IoHandleRef handle,
                                     OTF2_LockType lockType) override;

    virtual void
    writeProgramBeginEvent(OTF2_LocationRef location, OTF2_TimeStamp time,
                           OTF2_AttributeList *attributes,
                           OTF2_StringRef programName,
                           uint32_t numberOfArguments,
                           const OTF2_StringRef *programArguments) override;

    virtual void writeProgramEndEvent(OTF2_LocationRef location,
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