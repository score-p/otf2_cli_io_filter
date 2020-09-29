#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <cstddef>
#include <functional>
#include <memory>
#include <otf2/OTF2_GeneralDefinitions.h>
#include <string>
#include <unordered_set>

extern "C"
{
#include <otf2/otf2.h>
}

#include <filter.hpp>
#include <otf2_handler.hpp>

using archive_deleter = std::function<void(OTF2_Archive *)>;
using archive_ptr     = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void(OTF2_EvtWriter *)>;
using event_writer_ptr     = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

class TraceWriter : public Otf2Handler
{
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    virtual ~TraceWriter();

    /*
     * Handle global definitions
     */

    virtual void
    handleGlobalClockProperties(uint64_t timerResolution, uint64_t globalOffset, uint64_t traceLength) override;

    virtual void
    handleGlobalParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name, OTF2_ParadigmClass paradigmClass) override;

    virtual void
    handleGlobalParadigmProperty(OTF2_Paradigm         paradigm,
                                 OTF2_ParadigmProperty property,
                                 OTF2_Type             type,
                                 OTF2_AttributeValue   value) override;

    virtual void
    handleGlobalIoParadigm(OTF2_IoParadigmRef             self,
                           OTF2_StringRef                 identification,
                           OTF2_StringRef                 name,
                           OTF2_IoParadigmClass           ioParadigmClass,
                           OTF2_IoParadigmFlag            ioParadigmFlags,
                           uint8_t                        numberOfProperties,
                           const OTF2_IoParadigmProperty *properties,
                           const OTF2_Type *              types,
                           const OTF2_AttributeValue *    values) override;

    virtual void
    handleGlobalString(OTF2_StringRef self, const char *string) override;

    virtual void
    handleGlobalAttribute(OTF2_AttributeRef self,
                          OTF2_StringRef    name,
                          OTF2_StringRef    description,
                          OTF2_Type         type) override;

    virtual void
    handleGlobalSystemTreeNode(OTF2_SystemTreeNodeRef self,
                               OTF2_StringRef         name,
                               OTF2_StringRef         className,
                               OTF2_SystemTreeNodeRef parent) override;

    virtual void
    handleGlobalLocationGroup(OTF2_LocationGroupRef  self,
                              OTF2_StringRef         name,
                              OTF2_LocationGroupType locationGroupType,
                              OTF2_SystemTreeNodeRef systemTreeParent) override;

    virtual void
    handleGlobalLocation(OTF2_LocationRef      self,
                         OTF2_StringRef        name,
                         OTF2_LocationType     locationType,
                         uint64_t              numberOfEvents,
                         OTF2_LocationGroupRef locationGroup) override;

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
                       uint32_t        endLineNumber) override;

    virtual void
    handleGlobalCallsite(OTF2_CallsiteRef self,
                         OTF2_StringRef   sourceFile,
                         uint32_t         lineNumber,
                         OTF2_RegionRef   enteredRegion,
                         OTF2_RegionRef   leftRegion) override;

    virtual void
    handleGlobalCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent, OTF2_RegionRef region) override;

    virtual void
    handleGlobalGroup(OTF2_GroupRef   self,
                      OTF2_StringRef  name,
                      OTF2_GroupType  groupType,
                      OTF2_Paradigm   paradigm,
                      OTF2_GroupFlag  groupFlags,
                      uint32_t        numberOfMembers,
                      const uint64_t *members) override;

    virtual void
    handleGlobalMetricMember(OTF2_MetricMemberRef self,
                             OTF2_StringRef       name,
                             OTF2_StringRef       description,
                             OTF2_MetricType      metricType,
                             OTF2_MetricMode      metricMode,
                             OTF2_Type            valueType,
                             OTF2_Base            base,
                             int64_t              exponent,
                             OTF2_StringRef       unit) override;

    virtual void
    handleGlobalMetricClass(OTF2_MetricRef              self,
                            uint8_t                     numberOfMetrics,
                            const OTF2_MetricMemberRef *metricMembers,
                            OTF2_MetricOccurrence       metricOccurrence,
                            OTF2_RecorderKind           recorderKind) override;

    virtual void
    handleGlobalMetricInstance(OTF2_MetricRef   self,
                               OTF2_MetricRef   metricClass,
                               OTF2_LocationRef recorder,
                               OTF2_MetricScope metricScope,
                               uint64_t         scope) override;

    virtual void
    handleGlobalComm(OTF2_CommRef self, OTF2_StringRef name, OTF2_GroupRef group, OTF2_CommRef parent) override;

    virtual void
    handleGlobalParameter(OTF2_ParameterRef self, OTF2_StringRef name, OTF2_ParameterType parameterType) override;

    virtual void
    handleGlobalRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name, OTF2_CommRef comm) override;

    virtual void
    handleGlobalMetricClassRecorder(OTF2_MetricRef metric, OTF2_LocationRef recorder) override;

    virtual void
    handleGlobalSystemTreeNodeProperty(OTF2_SystemTreeNodeRef systemTreeNode,
                                       OTF2_StringRef         name,
                                       OTF2_Type              type,
                                       OTF2_AttributeValue    value) override;

    virtual void
    handleGlobalSystemTreeNodeDomain(OTF2_SystemTreeNodeRef systemTreeNode,
                                     OTF2_SystemTreeDomain  systemTreeDomain) override;

    virtual void
    handleGlobalLocationGroupProperty(OTF2_LocationGroupRef locationGroup,
                                      OTF2_StringRef        name,
                                      OTF2_Type             type,
                                      OTF2_AttributeValue   value) override;

    virtual void
    handleGlobalLocationProperty(OTF2_LocationRef    location,
                                 OTF2_StringRef      name,
                                 OTF2_Type           type,
                                 OTF2_AttributeValue value) override;

    virtual void
    handleGlobalCartDimension(OTF2_CartDimensionRef self,
                              OTF2_StringRef        name,
                              uint32_t              size,
                              OTF2_CartPeriodicity  cartPeriodicity) override;

    virtual void
    handleGlobalCartTopology(OTF2_CartTopologyRef         self,
                             OTF2_StringRef               name,
                             OTF2_CommRef                 communicator,
                             uint8_t                      numberOfDimensions,
                             const OTF2_CartDimensionRef *cartDimensions) override;

    virtual void
    handleGlobalCartCoordinate(OTF2_CartTopologyRef cartTopology,
                               uint32_t             rank,
                               uint8_t              numberOfDimensions,
                               const uint32_t *     coordinates) override;

    virtual void
    handleGlobalSourceCodeLocation(OTF2_SourceCodeLocationRef self, OTF2_StringRef file, uint32_t lineNumber) override;

    virtual void
    handleGlobalCallingContext(OTF2_CallingContextRef     self,
                               OTF2_RegionRef             region,
                               OTF2_SourceCodeLocationRef sourceCodeLocation,
                               OTF2_CallingContextRef     parent) override;

    virtual void
    handleGlobalCallingContextProperty(OTF2_CallingContextRef callingContext,
                                       OTF2_StringRef         name,
                                       OTF2_Type              type,
                                       OTF2_AttributeValue    value) override;

    virtual void
    handleGlobalInterruptGenerator(OTF2_InterruptGeneratorRef  self,
                                   OTF2_StringRef              name,
                                   OTF2_InterruptGeneratorMode interruptGeneratorMode,
                                   OTF2_Base                   base,
                                   int64_t                     exponent,
                                   uint64_t                    period) override;

    virtual void
    handleGlobalIoFileProperty(OTF2_IoFileRef      ioFile,
                               OTF2_StringRef      name,
                               OTF2_Type           type,
                               OTF2_AttributeValue value) override;

    virtual void
    handleGlobalIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope) override;

    virtual void
    handleGlobalIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope) override;

    virtual void
    handleGlobalIoHandle(OTF2_IoHandleRef   self,
                         OTF2_StringRef     name,
                         OTF2_IoFileRef     file,
                         OTF2_IoParadigmRef ioParadigm,
                         OTF2_IoHandleFlag  ioHandleFlags,
                         OTF2_CommRef       comm,
                         OTF2_IoHandleRef   parent) override;

    virtual void
    handleGlobalIoPreCreatedHandleState(OTF2_IoHandleRef  ioHandle,
                                        OTF2_IoAccessMode mode,
                                        OTF2_IoStatusFlag statusFlags) override;

    virtual void
    handleGlobalCallpathParameter(OTF2_CallpathRef    callpath,
                                  OTF2_ParameterRef   parameter,
                                  OTF2_Type           type,
                                  OTF2_AttributeValue value) override;

    /*
     * Handle local definitions
     */

    virtual void
    handleLocalMappingTable(OTF2_LocationRef  readLocation,
                            OTF2_MappingType  mappingType,
                            const OTF2_IdMap *idMap) override;

    virtual void
    handleLocalClockOffset(OTF2_LocationRef readLocation,
                           OTF2_TimeStamp   time,
                           int64_t          offset,
                           double           standardDeviation) override;

    /*
     * Handle events.
     */

    virtual void
    handleBufferFlushEvent(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           OTF2_AttributeList *attributes,
                           OTF2_TimeStamp      stopTime) override;

    virtual void
    handleMeasurementOnOffEvent(OTF2_LocationRef     location,
                                OTF2_TimeStamp       time,
                                OTF2_AttributeList * attributes,
                                OTF2_MeasurementMode measurementMode) override;

    virtual void
    handleEnterEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) override;

    virtual void
    handleLeaveEvent(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef      region) override;

    virtual void
    handleMpiSendEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            receiver,
                       OTF2_CommRef        communicator,
                       uint32_t            msgTag,
                       uint64_t            msgLength) override;

    virtual void
    handleMpiIsendEvent(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        OTF2_AttributeList *attributes,
                        uint32_t            receiver,
                        OTF2_CommRef        communicator,
                        uint32_t            msgTag,
                        uint64_t            msgLength,
                        uint64_t            requestID) override;

    virtual void
    handleMpiIsendCompleteEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                uint64_t            requestID) override;

    virtual void
    handleMpiIrecvRequestEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               uint64_t            requestID) override;

    virtual void
    handleMpiRecvEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            sender,
                       OTF2_CommRef        communicator,
                       uint32_t            msgTag,
                       uint64_t            msgLength) override;

    virtual void
    handleMpiIrecvEvent(OTF2_LocationRef    location,
                        OTF2_TimeStamp      time,
                        OTF2_AttributeList *attributes,
                        uint32_t            sender,
                        OTF2_CommRef        communicator,
                        uint32_t            msgTag,
                        uint64_t            msgLength,
                        uint64_t            requestID) override;

    virtual void
    handleMpiRequestTestEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint64_t            requestID) override;

    virtual void
    handleMpiRequestCancelledEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   uint64_t            requestID) override;

    virtual void
    handleMpiCollectiveBeginEvent(OTF2_LocationRef    location,
                                  OTF2_TimeStamp      time,
                                  OTF2_AttributeList *attributes) override;

    virtual void
    handleMpiCollectiveEndEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CollectiveOp   collectiveOp,
                                OTF2_CommRef        communicator,
                                uint32_t            root,
                                uint64_t            sizeSent,
                                uint64_t            sizeReceived) override;

    virtual void
    handleOmpForkEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       uint32_t            numberOfRequestedThreads) override;

    virtual void
    handleOmpJoinEvent(OTF2_LocationRef location, OTF2_TimeStamp time, OTF2_AttributeList *attributes) override;

    virtual void
    handleOmpAcquireLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint32_t            lockID,
                              uint32_t            acquisitionOrder) override;

    virtual void
    handleOmpReleaseLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              uint32_t            lockID,
                              uint32_t            acquisitionOrder) override;

    virtual void
    handleOmpTaskCreateEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             uint64_t            taskID) override;

    virtual void
    handleOmpTaskSwitchEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             uint64_t            taskID) override;

    virtual void
    handleOmpTaskCompleteEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               uint64_t            taskID) override;

    virtual void
    handleMetricEvent(OTF2_LocationRef        location,
                      OTF2_TimeStamp          time,
                      OTF2_AttributeList *    attributes,
                      OTF2_MetricRef          metric,
                      uint8_t                 numberOfMetrics,
                      const OTF2_Type *       typeIDs,
                      const OTF2_MetricValue *metricValues) override;

    virtual void
    handleParameterStringEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_ParameterRef   parameter,
                               OTF2_StringRef      string) override;

    virtual void
    handleParameterIntEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_ParameterRef   parameter,
                            int64_t             value) override;

    virtual void
    handleParameterUnsignedIntEvent(OTF2_LocationRef    location,
                                    OTF2_TimeStamp      time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_ParameterRef   parameter,
                                    uint64_t            value) override;

    virtual void
    handleRmaWinCreateEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_RmaWinRef      win) override;

    virtual void
    handleRmaWinDestroyEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win) override;

    virtual void
    handleRmaCollectiveBeginEvent(OTF2_LocationRef    location,
                                  OTF2_TimeStamp      time,
                                  OTF2_AttributeList *attributes) override;

    virtual void
    handleRmaCollectiveEndEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CollectiveOp   collectiveOp,
                                OTF2_RmaSyncLevel   syncLevel,
                                OTF2_RmaWinRef      win,
                                uint32_t            root,
                                uint64_t            bytesSent,
                                uint64_t            bytesReceived) override;

    virtual void
    handleRmaGroupSyncEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_RmaSyncLevel   syncLevel,
                            OTF2_RmaWinRef      win,
                            OTF2_GroupRef       group) override;

    virtual void
    handleRmaRequestLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId,
                              OTF2_LockType       lockType) override;

    virtual void
    handleRmaAcquireLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId,
                              OTF2_LockType       lockType) override;

    virtual void
    handleRmaTryLockEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_RmaWinRef      win,
                          uint32_t            remote,
                          uint64_t            lockId,
                          OTF2_LockType       lockType) override;

    virtual void
    handleRmaReleaseLockEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_RmaWinRef      win,
                              uint32_t            remote,
                              uint64_t            lockId) override;

    virtual void
    handleRmaSyncEvent(OTF2_LocationRef    location,
                       OTF2_TimeStamp      time,
                       OTF2_AttributeList *attributes,
                       OTF2_RmaWinRef      win,
                       uint32_t            remote,
                       OTF2_RmaSyncType    syncType) override;

    virtual void
    handleRmaWaitChangeEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_RmaWinRef      win) override;

    virtual void
    handleRmaPutEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            bytes,
                      uint64_t            matchingId) override;

    virtual void
    handleRmaGetEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_RmaWinRef      win,
                      uint32_t            remote,
                      uint64_t            bytes,
                      uint64_t            matchingId) override;

    virtual void
    handleRmaAtomicEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_RmaWinRef      win,
                         uint32_t            remote,
                         OTF2_RmaAtomicType  type,
                         uint64_t            bytesSent,
                         uint64_t            bytesReceived,
                         uint64_t            matchingId) override;

    virtual void
    handleRmaOpCompleteBlockingEvent(OTF2_LocationRef    location,
                                     OTF2_TimeStamp      time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef      win,
                                     uint64_t            matchingId) override;

    virtual void
    handleRmaOpCompleteNonBlockingEvent(OTF2_LocationRef    location,
                                        OTF2_TimeStamp      time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef      win,
                                        uint64_t            matchingId) override;

    virtual void
    handleRmaOpTestEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_RmaWinRef      win,
                         uint64_t            matchingId) override;

    virtual void
    handleRmaOpCompleteRemoteEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RmaWinRef      win,
                                   uint64_t            matchingId) override;

    virtual void
    handleThreadForkEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_Paradigm       model,
                          uint32_t            numberOfRequestedThreads) override;

    virtual void
    handleThreadJoinEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_Paradigm       model) override;

    virtual void
    handleThreadTeamBeginEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_CommRef        threadTeam) override;

    virtual void
    handleThreadTeamEndEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_CommRef        threadTeam) override;

    virtual void
    handleThreadAcquireLockEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm       model,
                                 uint32_t            lockID,
                                 uint32_t            acquisitionOrder) override;

    virtual void
    handleThreadReleaseLockEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_Paradigm       model,
                                 uint32_t            lockID,
                                 uint32_t            acquisitionOrder) override;

    virtual void
    handleThreadTaskCreateEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CommRef        threadTeam,
                                uint32_t            creatingThread,
                                uint32_t            generationNumber) override;

    virtual void
    handleThreadTaskSwitchEvent(OTF2_LocationRef    location,
                                OTF2_TimeStamp      time,
                                OTF2_AttributeList *attributes,
                                OTF2_CommRef        threadTeam,
                                uint32_t            creatingThread,
                                uint32_t            generationNumber) override;

    virtual void
    handleThreadTaskCompleteEvent(OTF2_LocationRef    location,
                                  OTF2_TimeStamp      time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_CommRef        threadTeam,
                                  uint32_t            creatingThread,
                                  uint32_t            generationNumber) override;

    virtual void
    handleThreadCreateEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_CommRef        threadContingent,
                            uint64_t            sequenceCount) override;

    virtual void
    handleThreadBeginEvent(OTF2_LocationRef    location,
                           OTF2_TimeStamp      time,
                           OTF2_AttributeList *attributes,
                           OTF2_CommRef        threadContingent,
                           uint64_t            sequenceCount) override;

    virtual void
    handleThreadWaitEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          OTF2_CommRef        threadContingent,
                          uint64_t            sequenceCount) override;

    virtual void
    handleThreadEndEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_CommRef        threadContingent,
                         uint64_t            sequenceCount) override;

    virtual void
    handleCallingContextEnterEvent(OTF2_LocationRef       location,
                                   OTF2_TimeStamp         time,
                                   OTF2_AttributeList *   attributes,
                                   OTF2_CallingContextRef callingContext,
                                   uint32_t               unwindDistance) override;

    virtual void
    handleCallingContextLeaveEvent(OTF2_LocationRef       location,
                                   OTF2_TimeStamp         time,
                                   OTF2_AttributeList *   attributes,
                                   OTF2_CallingContextRef callingContext) override;

    virtual void
    handleCallingContextSampleEvent(OTF2_LocationRef           location,
                                    OTF2_TimeStamp             time,
                                    OTF2_AttributeList *       attributes,
                                    OTF2_CallingContextRef     callingContext,
                                    uint32_t                   unwindDistance,
                                    OTF2_InterruptGeneratorRef interruptGenerator) override;

    virtual void
    handleIoCreateHandleEvent(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList *attributes,
                              OTF2_IoHandleRef    handle,
                              OTF2_IoAccessMode   mode,
                              OTF2_IoCreationFlag creationFlags,
                              OTF2_IoStatusFlag   statusFlags) override;

    virtual void
    handleIoDestroyHandleEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_IoHandleRef    handle) override;

    virtual void
    handleIoDuplicateHandleEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_IoHandleRef    oldHandle,
                                 OTF2_IoHandleRef    newHandle,
                                 OTF2_IoStatusFlag   statusFlags) override;

    virtual void
    handleIoSeekEvent(OTF2_LocationRef    location,
                      OTF2_TimeStamp      time,
                      OTF2_AttributeList *attributes,
                      OTF2_IoHandleRef    handle,
                      int64_t             offsetRequest,
                      OTF2_IoSeekOption   whence,
                      uint64_t            offsetResult) override;

    virtual void
    handleIoChangeStatusFlagsEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_IoHandleRef    handle,
                                   OTF2_IoStatusFlag   statusFlags) override;

    virtual void
    handleIoDeleteFileEvent(OTF2_LocationRef    location,
                            OTF2_TimeStamp      time,
                            OTF2_AttributeList *attributes,
                            OTF2_IoParadigmRef  ioParadigm,
                            OTF2_IoFileRef      file) override;

    virtual void
    handleIoOperationBeginEvent(OTF2_LocationRef     location,
                                OTF2_TimeStamp       time,
                                OTF2_AttributeList * attributes,
                                OTF2_IoHandleRef     handle,
                                OTF2_IoOperationMode mode,
                                OTF2_IoOperationFlag operationFlags,
                                uint64_t             bytesRequest,
                                uint64_t             matchingId) override;

    virtual void
    handleIoOperationTestEvent(OTF2_LocationRef    location,
                               OTF2_TimeStamp      time,
                               OTF2_AttributeList *attributes,
                               OTF2_IoHandleRef    handle,
                               uint64_t            matchingId) override;

    virtual void
    handleIoOperationIssuedEvent(OTF2_LocationRef    location,
                                 OTF2_TimeStamp      time,
                                 OTF2_AttributeList *attributes,
                                 OTF2_IoHandleRef    handle,
                                 uint64_t            matchingId) override;

    virtual void
    handleIoOperationCompleteEvent(OTF2_LocationRef    location,
                                   OTF2_TimeStamp      time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_IoHandleRef    handle,
                                   uint64_t            bytesResult,
                                   uint64_t            matchingId) override;

    virtual void
    handleIoOperationCancelledEvent(OTF2_LocationRef    location,
                                    OTF2_TimeStamp      time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_IoHandleRef    handle,
                                    uint64_t            matchingId) override;

    virtual void
    handleIoAcquireLockEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_IoHandleRef    handle,
                             OTF2_LockType       lockType) override;

    virtual void
    handleIoReleaseLockEvent(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList *attributes,
                             OTF2_IoHandleRef    handle,
                             OTF2_LockType       lockType) override;

    virtual void
    handleIoTryLockEvent(OTF2_LocationRef    location,
                         OTF2_TimeStamp      time,
                         OTF2_AttributeList *attributes,
                         OTF2_IoHandleRef    handle,
                         OTF2_LockType       lockType) override;

    virtual void
    handleProgramBeginEvent(OTF2_LocationRef      location,
                            OTF2_TimeStamp        time,
                            OTF2_AttributeList *  attributes,
                            OTF2_StringRef        programName,
                            uint32_t              numberOfArguments,
                            const OTF2_StringRef *programArguments) override;

    virtual void
    handleProgramEndEvent(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          OTF2_AttributeList *attributes,
                          int64_t             exitStatus) override;

    void
    register_filter(IFilterCallbacks &filter);

  private:
    static OTF2_FlushCallbacks           m_flush_callbacks;
    archive_ptr                          m_archive;
    OTF2_GlobalDefWriter *               m_def_writer;
    std::unordered_set<OTF2_LocationRef> m_locations;

    Filter<GlobalClockPropertiesFilter>         m_global_ClockProperties_filter;
    Filter<GlobalParadigmFilter>                m_global_Paradigm_filter;
    Filter<GlobalParadigmPropertyFilter>        m_global_ParadigmProperty_filter;
    Filter<GlobalIoParadigmFilter>              m_global_IoParadigm_filter;
    Filter<GlobalStringFilter>                  m_global_String_filter;
    Filter<GlobalAttributeFilter>               m_global_Attribute_filter;
    Filter<GlobalSystemTreeNodeFilter>          m_global_SystemTreeNode_filter;
    Filter<GlobalLocationGroupFilter>           m_global_LocationGroup_filter;
    Filter<GlobalLocationFilter>                m_global_Location_filter;
    Filter<GlobalRegionFilter>                  m_global_Region_filter;
    Filter<GlobalCallsiteFilter>                m_global_Callsite_filter;
    Filter<GlobalCallpathFilter>                m_global_Callpath_filter;
    Filter<GlobalGroupFilter>                   m_global_Group_filter;
    Filter<GlobalMetricMemberFilter>            m_global_MetricMember_filter;
    Filter<GlobalMetricClassFilter>             m_global_MetricClass_filter;
    Filter<GlobalMetricInstanceFilter>          m_global_MetricInstance_filter;
    Filter<GlobalCommFilter>                    m_global_Comm_filter;
    Filter<GlobalParameterFilter>               m_global_Parameter_filter;
    Filter<GlobalRmaWinFilter>                  m_global_RmaWin_filter;
    Filter<GlobalMetricClassRecorderFilter>     m_global_MetricClassRecorder_filter;
    Filter<GlobalSystemTreeNodePropertyFilter>  m_global_SystemTreeNodeProperty_filter;
    Filter<GlobalSystemTreeNodeDomainFilter>    m_global_SystemTreeNodeDomain_filter;
    Filter<GlobalLocationGroupPropertyFilter>   m_global_LocationGroupProperty_filter;
    Filter<GlobalLocationPropertyFilter>        m_global_LocationProperty_filter;
    Filter<GlobalCartDimensionFilter>           m_global_CartDimension_filter;
    Filter<GlobalCartTopologyFilter>            m_global_CartTopology_filter;
    Filter<GlobalCartCoordinateFilter>          m_global_CartCoordinate_filter;
    Filter<GlobalSourceCodeLocationFilter>      m_global_SourceCodeLocation_filter;
    Filter<GlobalCallingContextFilter>          m_global_CallingContext_filter;
    Filter<GlobalCallingContextPropertyFilter>  m_global_CallingContextProperty_filter;
    Filter<GlobalInterruptGeneratorFilter>      m_global_InterruptGenerator_filter;
    Filter<GlobalIoFilePropertyFilter>          m_global_IoFileProperty_filter;
    Filter<GlobalIoRegularFileFilter>           m_global_IoRegularFile_filter;
    Filter<GlobalIoDirectoryFilter>             m_global_IoDirectory_filter;
    Filter<GlobalIoHandleFilter>                m_global_IoHandle_filter;
    Filter<GlobalIoPreCreatedHandleStateFilter> m_global_IoPreCreatedHandleState_filter;
    Filter<GlobalCallpathParameterFilter>       m_global_CallpathParameter_filter;

    Filter<EventBufferFlushFilter>              m_event_BufferFlush_filter;
    Filter<EventMeasurementOnOffFilter>         m_event_MeasurementOnOff_filter;
    Filter<EventEnterFilter>                    m_event_Enter_filter;
    Filter<EventLeaveFilter>                    m_event_Leave_filter;
    Filter<EventMpiSendFilter>                  m_event_MpiSend_filter;
    Filter<EventMpiIsendFilter>                 m_event_MpiIsend_filter;
    Filter<EventMpiIsendCompleteFilter>         m_event_MpiIsendComplete_filter;
    Filter<EventMpiIrecvRequestFilter>          m_event_MpiIrecvRequest_filter;
    Filter<EventMpiRecvFilter>                  m_event_MpiRecv_filter;
    Filter<EventMpiIrecvFilter>                 m_event_MpiIrecv_filter;
    Filter<EventMpiRequestTestFilter>           m_event_MpiRequestTest_filter;
    Filter<EventMpiRequestCancelledFilter>      m_event_MpiRequestCancelled_filter;
    Filter<EventMpiCollectiveBeginFilter>       m_event_MpiCollectiveBegin_filter;
    Filter<EventMpiCollectiveEndFilter>         m_event_MpiCollectiveEnd_filter;
    Filter<EventOmpForkFilter>                  m_event_OmpFork_filter;
    Filter<EventOmpJoinFilter>                  m_event_OmpJoin_filter;
    Filter<EventOmpAcquireLockFilter>           m_event_OmpAcquireLock_filter;
    Filter<EventOmpReleaseLockFilter>           m_event_OmpReleaseLock_filter;
    Filter<EventOmpTaskCreateFilter>            m_event_OmpTaskCreate_filter;
    Filter<EventOmpTaskSwitchFilter>            m_event_OmpTaskSwitch_filter;
    Filter<EventOmpTaskCompleteFilter>          m_event_OmpTaskComplete_filter;
    Filter<EventMetricFilter>                   m_event_Metric_filter;
    Filter<EventParameterStringFilter>          m_event_ParameterString_filter;
    Filter<EventParameterIntFilter>             m_event_ParameterInt_filter;
    Filter<EventParameterUnsignedIntFilter>     m_event_ParameterUnsignedInt_filter;
    Filter<EventRmaWinCreateFilter>             m_event_RmaWinCreate_filter;
    Filter<EventRmaWinDestroyFilter>            m_event_RmaWinDestroy_filter;
    Filter<EventRmaCollectiveBeginFilter>       m_event_RmaCollectiveBegin_filter;
    Filter<EventRmaCollectiveEndFilter>         m_event_RmaCollectiveEnd_filter;
    Filter<EventRmaGroupSyncFilter>             m_event_RmaGroupSync_filter;
    Filter<EventRmaRequestLockFilter>           m_event_RmaRequestLock_filter;
    Filter<EventRmaAcquireLockFilter>           m_event_RmaAcquireLock_filter;
    Filter<EventRmaTryLockFilter>               m_event_RmaTryLock_filter;
    Filter<EventRmaReleaseLockFilter>           m_event_RmaReleaseLock_filter;
    Filter<EventRmaSyncFilter>                  m_event_RmaSync_filter;
    Filter<EventRmaWaitChangeFilter>            m_event_RmaWaitChange_filter;
    Filter<EventRmaPutFilter>                   m_event_RmaPut_filter;
    Filter<EventRmaGetFilter>                   m_event_RmaGet_filter;
    Filter<EventRmaAtomicFilter>                m_event_RmaAtomic_filter;
    Filter<EventRmaOpCompleteBlockingFilter>    m_event_RmaOpCompleteBlocking_filter;
    Filter<EventRmaOpCompleteNonBlockingFilter> m_event_RmaOpCompleteNonBlocking_filter;
    Filter<EventRmaOpTestFilter>                m_event_RmaOpTest_filter;
    Filter<EventRmaOpCompleteRemoteFilter>      m_event_RmaOpCompleteRemote_filter;
    Filter<EventThreadForkFilter>               m_event_ThreadFork_filter;
    Filter<EventThreadJoinFilter>               m_event_ThreadJoin_filter;
    Filter<EventThreadTeamBeginFilter>          m_event_ThreadTeamBegin_filter;
    Filter<EventThreadTeamEndFilter>            m_event_ThreadTeamEnd_filter;
    Filter<EventThreadAcquireLockFilter>        m_event_ThreadAcquireLock_filter;
    Filter<EventThreadReleaseLockFilter>        m_event_ThreadReleaseLock_filter;
    Filter<EventThreadTaskCreateFilter>         m_event_ThreadTaskCreate_filter;
    Filter<EventThreadTaskSwitchFilter>         m_event_ThreadTaskSwitch_filter;
    Filter<EventThreadTaskCompleteFilter>       m_event_ThreadTaskComplete_filter;
    Filter<EventThreadCreateFilter>             m_event_ThreadCreate_filter;
    Filter<EventThreadBeginFilter>              m_event_ThreadBegin_filter;
    Filter<EventThreadWaitFilter>               m_event_ThreadWait_filter;
    Filter<EventThreadEndFilter>                m_event_ThreadEnd_filter;
    Filter<EventCallingContextEnterFilter>      m_event_CallingContextEnter_filter;
    Filter<EventCallingContextLeaveFilter>      m_event_CallingContextLeave_filter;
    Filter<EventCallingContextSampleFilter>     m_event_CallingContextSample_filter;
    Filter<EventIoCreateHandleFilter>           m_event_IoCreateHandle_filter;
    Filter<EventIoDestroyHandleFilter>          m_event_IoDestroyHandle_filter;
    Filter<EventIoDuplicateHandleFilter>        m_event_IoDuplicateHandle_filter;
    Filter<EventIoSeekFilter>                   m_event_IoSeek_filter;
    Filter<EventIoChangeStatusFlagsFilter>      m_event_IoChangeStatusFlags_filter;
    Filter<EventIoDeleteFileFilter>             m_event_IoDeleteFile_filter;
    Filter<EventIoOperationBeginFilter>         m_event_IoOperationBegin_filter;
    Filter<EventIoOperationTestFilter>          m_event_IoOperationTest_filter;
    Filter<EventIoOperationIssuedFilter>        m_event_IoOperationIssued_filter;
    Filter<EventIoOperationCompleteFilter>      m_event_IoOperationComplete_filter;
    Filter<EventIoOperationCancelledFilter>     m_event_IoOperationCancelled_filter;
    Filter<EventIoAcquireLockFilter>            m_event_IoAcquireLock_filter;
    Filter<EventIoReleaseLockFilter>            m_event_IoReleaseLock_filter;
    Filter<EventIoTryLockFilter>                m_event_IoTryLock_filter;
    Filter<EventProgramBeginFilter>             m_event_ProgramBegin_filter;
    Filter<EventProgramEndFilter>               m_event_ProgramEnd_filter;
};

#endif /* TRACE_WRITER_H */