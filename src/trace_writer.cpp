#include <cassert>
#include <trace_writer.hpp>

OTF2_FlushType pre_flush(void *userData, OTF2_FileType fileType,
                         OTF2_LocationRef location, void *callerData,
                         bool final) {
    return OTF2_FLUSH;
}

OTF2_FlushCallbacks TraceWriter::m_flush_callbacks = {
    .otf2_pre_flush = pre_flush, .otf2_post_flush = nullptr};

void delete_event_writer(OTF2_EvtWriter *writer, OTF2_Archive *archive) {
    if (nullptr != archive && nullptr != writer) {
        OTF2_Archive_CloseEvtWriter(archive, writer);
    }
}

void delete_archive(OTF2_Archive *archive) {
    if (nullptr != archive) {
        OTF2_Archive_Close(archive);
    }
}

TraceWriter::TraceWriter(const std::string &path)
    : m_archive(nullptr, delete_archive) {
    auto *archive =
        OTF2_Archive_Open(path.c_str(), "trace", OTF2_FILEMODE_WRITE,
                          1024 * 1024 /* event chunk size */,
                          4 * 1024 * 1024 /* def chunk size */,
                          OTF2_SUBSTRATE_POSIX, OTF2_COMPRESSION_NONE);

    OTF2_Archive_SetFlushCallbacks(archive, &m_flush_callbacks, nullptr);
    OTF2_Archive_SetSerialCollectiveCallbacks(archive);
    m_archive.reset(archive);

    OTF2_Archive_OpenEvtFiles(archive);

    m_def_writer = OTF2_Archive_GetGlobalDefWriter(archive);
    assert(m_def_writer);
}

TraceWriter::~TraceWriter() {
    OTF2_Archive_CloseDefFiles(m_archive.get());
    for (const auto &[location, dummy] : m_event_writer) {
        OTF2_DefWriter *def_writer =
            OTF2_Archive_GetDefWriter(m_archive.get(), location);
        OTF2_Archive_CloseDefWriter(m_archive.get(), def_writer);
    }
    OTF2_Archive_CloseEvtFiles(m_archive.get());
}

void TraceWriter::handleClockProperties(uint64_t timerResolution,
                                        uint64_t globalOffset,
                                        uint64_t traceLength) {
    OTF2_GlobalDefWriter_WriteClockProperties(m_def_writer, timerResolution,
                                              globalOffset, traceLength);
}

void TraceWriter::handleParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name,
                                 OTF2_ParadigmClass paradigmClass) {
    OTF2_GlobalDefWriter_WriteParadigm(m_def_writer, paradigm, name,
                                       paradigmClass);
}

void TraceWriter::handleParadigmProperty(OTF2_Paradigm paradigm,
                                         OTF2_ParadigmProperty property,
                                         OTF2_Type type,
                                         OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteParadigmProperty(m_def_writer, paradigm, property,
                                               type, value);
}

void TraceWriter::handleIoParadigm(
    OTF2_IoParadigmRef self, OTF2_StringRef identification, OTF2_StringRef name,
    OTF2_IoParadigmClass ioParadigmClass, OTF2_IoParadigmFlag ioParadigmFlags,
    uint8_t numberOfProperties, const OTF2_IoParadigmProperty *properties,
    const OTF2_Type *types, const OTF2_AttributeValue *values) {
    OTF2_GlobalDefWriter_WriteIoParadigm(
        m_def_writer, self, identification, name, ioParadigmClass,
        ioParadigmFlags, numberOfProperties, properties, types, values);
}

void TraceWriter::handleString(OTF2_StringRef self, const char *string) {
    OTF2_GlobalDefWriter_WriteString(m_def_writer, self, string);
}

void TraceWriter::handleAttribute(OTF2_AttributeRef self, OTF2_StringRef name,
                                  OTF2_StringRef description, OTF2_Type type) {
    OTF2_GlobalDefWriter_WriteAttribute(m_def_writer, self, name, description,
                                        type);
}

void TraceWriter::handleSystemTreeNode(OTF2_SystemTreeNodeRef self,
                                       OTF2_StringRef name,
                                       OTF2_StringRef className,
                                       OTF2_SystemTreeNodeRef parent) {
    OTF2_GlobalDefWriter_WriteSystemTreeNode(m_def_writer, self, name,
                                             className, parent);
}

void TraceWriter::handleLocationGroup(OTF2_LocationGroupRef self,
                                      OTF2_StringRef name,
                                      OTF2_LocationGroupType locationGroupType,
                                      OTF2_SystemTreeNodeRef systemTreeParent) {
    OTF2_GlobalDefWriter_WriteLocationGroup(
        m_def_writer, self, name, locationGroupType, systemTreeParent);
}

void TraceWriter::handleLocation(OTF2_LocationRef self, OTF2_StringRef name,
                                 OTF2_LocationType locationType,
                                 uint64_t numberOfEvents,
                                 OTF2_LocationGroupRef locationGroup) {
    OTF2_GlobalDefWriter_WriteLocation(m_def_writer, self, name, locationType,
                                       numberOfEvents, locationGroup);
    auto search = m_event_writer.find(self);
    if (search == m_event_writer.end()) {
        m_event_writer.emplace(
            self,
            event_writer_ptr(OTF2_Archive_GetEvtWriter(m_archive.get(), self),
                             [this](OTF2_EvtWriter *writer) {
                                 delete_event_writer(writer, m_archive.get());
                             }));
    }
}

void TraceWriter::handleRegion(
    OTF2_RegionRef self, OTF2_StringRef name, OTF2_StringRef canonicalName,
    OTF2_StringRef description, OTF2_RegionRole regionRole,
    OTF2_Paradigm paradigm, OTF2_RegionFlag regionFlags,
    OTF2_StringRef sourceFile, uint32_t beginLineNumber,
    uint32_t endLineNumber) {
    OTF2_GlobalDefWriter_WriteRegion(
        m_def_writer, self, name, canonicalName, description, regionRole,
        paradigm, regionFlags, sourceFile, beginLineNumber, endLineNumber);
}

void TraceWriter::handleCallsite(OTF2_CallsiteRef self,
                                 OTF2_StringRef sourceFile, uint32_t lineNumber,
                                 OTF2_RegionRef enteredRegion,
                                 OTF2_RegionRef leftRegion) {
    OTF2_GlobalDefWriter_WriteCallsite(m_def_writer, self, sourceFile,
                                       lineNumber, enteredRegion, leftRegion);
}

void TraceWriter::handleCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent,
                                 OTF2_RegionRef region) {
    OTF2_GlobalDefWriter_WriteCallpath(m_def_writer, self, parent, region);
}

void TraceWriter::handleGroup(OTF2_GroupRef self, OTF2_StringRef name,
                              OTF2_GroupType groupType, OTF2_Paradigm paradigm,
                              OTF2_GroupFlag groupFlags,
                              uint32_t numberOfMembers,
                              const uint64_t *members) {
    OTF2_GlobalDefWriter_WriteGroup(m_def_writer, self, name, groupType,
                                    paradigm, groupFlags, numberOfMembers,
                                    members);
}

void TraceWriter::handleMetricMember(
    OTF2_MetricMemberRef self, OTF2_StringRef name, OTF2_StringRef description,
    OTF2_MetricType metricType, OTF2_MetricMode metricMode, OTF2_Type valueType,
    OTF2_Base base, int64_t exponent, OTF2_StringRef unit) {
    OTF2_GlobalDefWriter_WriteMetricMember(m_def_writer, self, name,
                                           description, metricType, metricMode,
                                           valueType, base, exponent, unit);
}

void TraceWriter::handleMetricClass(OTF2_MetricRef self,
                                    uint8_t numberOfMetrics,
                                    const OTF2_MetricMemberRef *metricMembers,
                                    OTF2_MetricOccurrence metricOccurrence,
                                    OTF2_RecorderKind recorderKind) {
    OTF2_GlobalDefWriter_WriteMetricClass(m_def_writer, self, numberOfMetrics,
                                          metricMembers, metricOccurrence,
                                          recorderKind);
}

void TraceWriter::handleMetricInstance(OTF2_MetricRef self,
                                       OTF2_MetricRef metricClass,
                                       OTF2_LocationRef recorder,
                                       OTF2_MetricScope metricScope,
                                       uint64_t scope) {
    OTF2_GlobalDefWriter_WriteMetricInstance(m_def_writer, self, metricClass,
                                             recorder, metricScope, scope);
}

void TraceWriter::handleComm(OTF2_CommRef self, OTF2_StringRef name,
                             OTF2_GroupRef group, OTF2_CommRef parent) {
    OTF2_GlobalDefWriter_WriteComm(m_def_writer, self, name, group, parent);
}

void TraceWriter::handleParameter(OTF2_ParameterRef self, OTF2_StringRef name,
                                  OTF2_ParameterType parameterType) {
    OTF2_GlobalDefWriter_WriteParameter(m_def_writer, self, name,
                                        parameterType);
}

void TraceWriter::handleRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name,
                               OTF2_CommRef comm) {
    OTF2_GlobalDefWriter_WriteRmaWin(m_def_writer, self, name, comm);
}

void TraceWriter::handleMetricClassRecorder(OTF2_MetricRef metric,
                                            OTF2_LocationRef recorder) {
    OTF2_GlobalDefWriter_WriteMetricClassRecorder(m_def_writer, metric,
                                                  recorder);
}

void TraceWriter::handleSystemTreeNodeProperty(
    OTF2_SystemTreeNodeRef systemTreeNode, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteSystemTreeNodeProperty(
        m_def_writer, systemTreeNode, name, type, value);
}

void TraceWriter::handleSystemTreeNodeDomain(
    OTF2_SystemTreeNodeRef systemTreeNode,
    OTF2_SystemTreeDomain systemTreeDomain) {
    OTF2_GlobalDefWriter_WriteSystemTreeNodeDomain(m_def_writer, systemTreeNode,
                                                   systemTreeDomain);
}

void TraceWriter::handleLocationGroupProperty(
    OTF2_LocationGroupRef locationGroup, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteLocationGroupProperty(m_def_writer, locationGroup,
                                                    name, type, value);
}

void TraceWriter::handleLocationProperty(OTF2_LocationRef location,
                                         OTF2_StringRef name, OTF2_Type type,
                                         OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteLocationProperty(m_def_writer, location, name,
                                               type, value);
}

void TraceWriter::handleCartDimension(OTF2_CartDimensionRef self,
                                      OTF2_StringRef name, uint32_t size,
                                      OTF2_CartPeriodicity cartPeriodicity) {
    OTF2_GlobalDefWriter_WriteCartDimension(m_def_writer, self, name, size,
                                            cartPeriodicity);
}

void TraceWriter::handleCartTopology(
    OTF2_CartTopologyRef self, OTF2_StringRef name, OTF2_CommRef communicator,
    uint8_t numberOfDimensions, const OTF2_CartDimensionRef *cartDimensions) {
    OTF2_GlobalDefWriter_WriteCartTopology(m_def_writer, self, name,
                                           communicator, numberOfDimensions,
                                           cartDimensions);
}

void TraceWriter::handleCartCoordinate(OTF2_CartTopologyRef cartTopology,
                                       uint32_t rank,
                                       uint8_t numberOfDimensions,
                                       const uint32_t *coordinates) {
    OTF2_GlobalDefWriter_WriteCartCoordinate(m_def_writer, cartTopology, rank,
                                             numberOfDimensions, coordinates);
}

void TraceWriter::handleSourceCodeLocation(OTF2_SourceCodeLocationRef self,
                                           OTF2_StringRef file,
                                           uint32_t lineNumber) {
    OTF2_GlobalDefWriter_WriteSourceCodeLocation(m_def_writer, self, file,
                                                 lineNumber);
}

void TraceWriter::handleCallingContext(
    OTF2_CallingContextRef self, OTF2_RegionRef region,
    OTF2_SourceCodeLocationRef sourceCodeLocation,
    OTF2_CallingContextRef parent) {
    OTF2_GlobalDefWriter_WriteCallingContext(m_def_writer, self, region,
                                             sourceCodeLocation, parent);
}

void TraceWriter::handleCallingContextProperty(
    OTF2_CallingContextRef callingContext, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteCallingContextProperty(
        m_def_writer, callingContext, name, type, value);
}

void TraceWriter::handleInterruptGenerator(
    OTF2_InterruptGeneratorRef self, OTF2_StringRef name,
    OTF2_InterruptGeneratorMode interruptGeneratorMode, OTF2_Base base,
    int64_t exponent, uint64_t period) {
    OTF2_GlobalDefWriter_WriteInterruptGenerator(m_def_writer, self, name,
                                                 interruptGeneratorMode, base,
                                                 exponent, period);
}

void TraceWriter::handleIoFileProperty(OTF2_IoFileRef ioFile,
                                       OTF2_StringRef name, OTF2_Type type,
                                       OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteIoFileProperty(m_def_writer, ioFile, name, type,
                                             value);
}

void TraceWriter::handleIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name,
                                      OTF2_SystemTreeNodeRef scope) {
    OTF2_GlobalDefWriter_WriteIoRegularFile(m_def_writer, self, name, scope);
}

void TraceWriter::handleIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name,
                                    OTF2_SystemTreeNodeRef scope) {
    OTF2_GlobalDefWriter_WriteIoDirectory(m_def_writer, self, name, scope);
}

void TraceWriter::handleIoHandle(OTF2_IoHandleRef self, OTF2_StringRef name,
                                 OTF2_IoFileRef file,
                                 OTF2_IoParadigmRef ioParadigm,
                                 OTF2_IoHandleFlag ioHandleFlags,
                                 OTF2_CommRef comm, OTF2_IoHandleRef parent) {
    OTF2_GlobalDefWriter_WriteIoHandle(m_def_writer, self, name, file,
                                       ioParadigm, ioHandleFlags, comm, parent);
}

void TraceWriter::handleIoPreCreatedHandleState(OTF2_IoHandleRef ioHandle,
                                                OTF2_IoAccessMode mode,
                                                OTF2_IoStatusFlag statusFlags) {
    OTF2_GlobalDefWriter_WriteIoPreCreatedHandleState(m_def_writer, ioHandle,
                                                      mode, statusFlags);
}

void TraceWriter::handleCallpathParameter(OTF2_CallpathRef callpath,
                                          OTF2_ParameterRef parameter,
                                          OTF2_Type type,
                                          OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteCallpathParameter(m_def_writer, callpath,
                                                parameter, type, value);
}

void TraceWriter::handleBufferFlushEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_TimeStamp stopTime) {
    OTF2_EvtWriter_BufferFlush(m_event_writer[location].get(), attributes, time,
                               stopTime);
}

void TraceWriter::handleMeasurementOnOffEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_MeasurementMode measurementMode) {
    OTF2_EvtWriter_MeasurementOnOff(m_event_writer[location].get(), attributes,
                                    time, measurementMode);
}

void TraceWriter::handleEnterEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RegionRef region) {
    OTF2_EvtWriter_Enter(m_event_writer[location].get(), attributes, time,
                         region);
}

void TraceWriter::handleLeaveEvent(OTF2_LocationRef location,
                                   OTF2_TimeStamp time,
                                   OTF2_AttributeList *attributes,
                                   OTF2_RegionRef region) {
    OTF2_EvtWriter_Leave(m_event_writer[location].get(), attributes, time,
                         region);
}

void TraceWriter::handleMpiSendEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     uint32_t receiver,
                                     OTF2_CommRef communicator, uint32_t msgTag,
                                     uint64_t msgLength) {
    OTF2_EvtWriter_MpiSend(m_event_writer[location].get(), attributes, time,
                           receiver, communicator, msgTag, msgLength);
}

void TraceWriter::handleMpiIsendEvent(OTF2_LocationRef location,
                                      OTF2_TimeStamp time,
                                      OTF2_AttributeList *attributes,
                                      uint32_t receiver,
                                      OTF2_CommRef communicator,
                                      uint32_t msgTag, uint64_t msgLength,
                                      uint64_t requestID) {
    OTF2_EvtWriter_MpiIsend(m_event_writer[location].get(), attributes, time,
                            receiver, communicator, msgTag, msgLength,
                            requestID);
}

void TraceWriter::handleMpiIsendCompleteEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              uint64_t requestID) {
    OTF2_EvtWriter_MpiIsendComplete(m_event_writer[location].get(), attributes,
                                    time, requestID);
}

void TraceWriter::handleMpiIrecvRequestEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             uint64_t requestID) {
    OTF2_EvtWriter_MpiIrecvRequest(m_event_writer[location].get(), attributes,
                                   time, requestID);
}

void TraceWriter::handleMpiRecvEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     uint32_t sender, OTF2_CommRef communicator,
                                     uint32_t msgTag, uint64_t msgLength) {
    OTF2_EvtWriter_MpiRecv(m_event_writer[location].get(), attributes, time,
                           sender, communicator, msgTag, msgLength);
}

void TraceWriter::handleMpiIrecvEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, uint32_t sender, OTF2_CommRef communicator,
    uint32_t msgTag, uint64_t msgLength, uint64_t requestID) {
    OTF2_EvtWriter_MpiIrecv(m_event_writer[location].get(), attributes, time,
                            sender, communicator, msgTag, msgLength, requestID);
}

void TraceWriter::handleMpiRequestTestEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint64_t requestID) {
    OTF2_EvtWriter_MpiRequestTest(m_event_writer[location].get(), attributes,
                                  time, requestID);
}

void TraceWriter::handleMpiRequestCancelledEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 uint64_t requestID) {
    OTF2_EvtWriter_MpiRequestCancelled(m_event_writer[location].get(),
                                       attributes, time, requestID);
}

void TraceWriter::handleMpiCollectiveBeginEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes) {
    OTF2_EvtWriter_MpiCollectiveBegin(m_event_writer[location].get(),
                                      attributes, time);
}

void TraceWriter::handleMpiCollectiveEndEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              OTF2_CollectiveOp collectiveOp,
                                              OTF2_CommRef communicator,
                                              uint32_t root, uint64_t sizeSent,
                                              uint64_t sizeReceived) {
    OTF2_EvtWriter_MpiCollectiveEnd(m_event_writer[location].get(), attributes,
                                    time, collectiveOp, communicator, root,
                                    sizeSent, sizeReceived);
}

void TraceWriter::handleOmpForkEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     uint32_t numberOfRequestedThreads) {
    OTF2_EvtWriter_OmpFork(m_event_writer[location].get(), attributes, time,
                           numberOfRequestedThreads);
}

void TraceWriter::handleOmpJoinEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes) {
    OTF2_EvtWriter_OmpJoin(m_event_writer[location].get(), attributes, time);
}

void TraceWriter::handleOmpAcquireLockEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint32_t lockID,
                                            uint32_t acquisitionOrder) {
    OTF2_EvtWriter_OmpAcquireLock(m_event_writer[location].get(), attributes,
                                  time, lockID, acquisitionOrder);
}

void TraceWriter::handleOmpReleaseLockEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            uint32_t lockID,
                                            uint32_t acquisitionOrder) {
    OTF2_EvtWriter_OmpReleaseLock(m_event_writer[location].get(), attributes,
                                  time, lockID, acquisitionOrder);
}

void TraceWriter::handleOmpTaskCreateEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t taskID) {
    OTF2_EvtWriter_OmpTaskCreate(m_event_writer[location].get(), attributes,
                                 time, taskID);
}

void TraceWriter::handleOmpTaskSwitchEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           uint64_t taskID) {
    OTF2_EvtWriter_OmpTaskSwitch(m_event_writer[location].get(), attributes,
                                 time, taskID);
}

void TraceWriter::handleOmpTaskCompleteEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             uint64_t taskID) {
    OTF2_EvtWriter_OmpTaskComplete(m_event_writer[location].get(), attributes,
                                   time, taskID);
}

void TraceWriter::handleMetricEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_MetricRef metric,
                                    uint8_t numberOfMetrics,
                                    const OTF2_Type *typeIDs,
                                    const OTF2_MetricValue *metricValues) {
    OTF2_EvtWriter_Metric(m_event_writer[location].get(), attributes, time,
                          metric, numberOfMetrics, typeIDs, metricValues);
}

void TraceWriter::handleParameterStringEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_ParameterRef parameter,
                                             OTF2_StringRef string) {
    OTF2_EvtWriter_ParameterString(m_event_writer[location].get(), attributes,
                                   time, parameter, string);
}

void TraceWriter::handleParameterIntEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_ParameterRef parameter,
                                          int64_t value) {
    OTF2_EvtWriter_ParameterInt(m_event_writer[location].get(), attributes,
                                time, parameter, value);
}

void TraceWriter::handleParameterUnsignedIntEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_ParameterRef parameter,
    uint64_t value) {
    OTF2_EvtWriter_ParameterUnsignedInt(m_event_writer[location].get(),
                                        attributes, time, parameter, value);
}

void TraceWriter::handleRmaWinCreateEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaWinRef win) {
    OTF2_EvtWriter_RmaWinCreate(m_event_writer[location].get(), attributes,
                                time, win);
}

void TraceWriter::handleRmaWinDestroyEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_RmaWinRef win) {
    OTF2_EvtWriter_RmaWinDestroy(m_event_writer[location].get(), attributes,
                                 time, win);
}

void TraceWriter::handleRmaCollectiveBeginEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes) {
    OTF2_EvtWriter_RmaCollectiveBegin(m_event_writer[location].get(),
                                      attributes, time);
}

void TraceWriter::handleRmaCollectiveEndEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_CollectiveOp collectiveOp,
    OTF2_RmaSyncLevel syncLevel, OTF2_RmaWinRef win, uint32_t root,
    uint64_t bytesSent, uint64_t bytesReceived) {
    OTF2_EvtWriter_RmaCollectiveEnd(m_event_writer[location].get(), attributes,
                                    time, collectiveOp, syncLevel, win, root,
                                    bytesSent, bytesReceived);
}

void TraceWriter::handleRmaGroupSyncEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_RmaSyncLevel syncLevel,
                                          OTF2_RmaWinRef win,
                                          OTF2_GroupRef group) {
    OTF2_EvtWriter_RmaGroupSync(m_event_writer[location].get(), attributes,
                                time, syncLevel, win, group);
}

void TraceWriter::handleRmaRequestLockEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_RmaWinRef win, uint32_t remote,
                                            uint64_t lockId,
                                            OTF2_LockType lockType) {
    OTF2_EvtWriter_RmaRequestLock(m_event_writer[location].get(), attributes,
                                  time, win, remote, lockId, lockType);
}

void TraceWriter::handleRmaAcquireLockEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_RmaWinRef win, uint32_t remote,
                                            uint64_t lockId,
                                            OTF2_LockType lockType) {
    OTF2_EvtWriter_RmaAcquireLock(m_event_writer[location].get(), attributes,
                                  time, win, remote, lockId, lockType);
}

void TraceWriter::handleRmaTryLockEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_RmaWinRef win, uint32_t remote,
                                        uint64_t lockId,
                                        OTF2_LockType lockType) {
    OTF2_EvtWriter_RmaTryLock(m_event_writer[location].get(), attributes, time,
                              win, remote, lockId, lockType);
}

void TraceWriter::handleRmaReleaseLockEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_RmaWinRef win, uint32_t remote,
                                            uint64_t lockId) {
    OTF2_EvtWriter_RmaReleaseLock(m_event_writer[location].get(), attributes,
                                  time, win, remote, lockId);
}

void TraceWriter::handleRmaSyncEvent(OTF2_LocationRef location,
                                     OTF2_TimeStamp time,
                                     OTF2_AttributeList *attributes,
                                     OTF2_RmaWinRef win, uint32_t remote,
                                     OTF2_RmaSyncType syncType) {
    OTF2_EvtWriter_RmaSync(m_event_writer[location].get(), attributes, time,
                           win, remote, syncType);
}

void TraceWriter::handleRmaWaitChangeEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_RmaWinRef win) {
    OTF2_EvtWriter_RmaWaitChange(m_event_writer[location].get(), attributes,
                                 time, win);
}

void TraceWriter::handleRmaPutEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_RmaWinRef win, uint32_t remote,
                                    uint64_t bytes, uint64_t matchingId) {
    OTF2_EvtWriter_RmaPut(m_event_writer[location].get(), attributes, time, win,
                          remote, bytes, matchingId);
}

void TraceWriter::handleRmaGetEvent(OTF2_LocationRef location,
                                    OTF2_TimeStamp time,
                                    OTF2_AttributeList *attributes,
                                    OTF2_RmaWinRef win, uint32_t remote,
                                    uint64_t bytes, uint64_t matchingId) {
    OTF2_EvtWriter_RmaGet(m_event_writer[location].get(), attributes, time, win,
                          remote, bytes, matchingId);
}

void TraceWriter::handleRmaAtomicEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_RmaWinRef win, uint32_t remote,
    OTF2_RmaAtomicType type, uint64_t bytesSent, uint64_t bytesReceived,
    uint64_t matchingId) {
    OTF2_EvtWriter_RmaAtomic(m_event_writer[location].get(), attributes, time,
                             win, remote, type, bytesSent, bytesReceived,
                             matchingId);
}

void TraceWriter::handleRmaOpCompleteBlockingEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_RmaWinRef win, uint64_t matchingId) {
    OTF2_EvtWriter_RmaOpCompleteBlocking(m_event_writer[location].get(),
                                         attributes, time, win, matchingId);
}

void TraceWriter::handleRmaOpCompleteNonBlockingEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_RmaWinRef win, uint64_t matchingId) {
    OTF2_EvtWriter_RmaOpCompleteNonBlocking(m_event_writer[location].get(),
                                            attributes, time, win, matchingId);
}

void TraceWriter::handleRmaOpTestEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_RmaWinRef win,
                                       uint64_t matchingId) {
    OTF2_EvtWriter_RmaOpTest(m_event_writer[location].get(), attributes, time,
                             win, matchingId);
}

void TraceWriter::handleRmaOpCompleteRemoteEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_RmaWinRef win,
                                                 uint64_t matchingId) {
    OTF2_EvtWriter_RmaOpCompleteRemote(m_event_writer[location].get(),
                                       attributes, time, win, matchingId);
}

void TraceWriter::handleThreadForkEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_Paradigm model,
                                        uint32_t numberOfRequestedThreads) {
    OTF2_EvtWriter_ThreadFork(m_event_writer[location].get(), attributes, time,
                              model, numberOfRequestedThreads);
}

void TraceWriter::handleThreadJoinEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_Paradigm model) {
    OTF2_EvtWriter_ThreadJoin(m_event_writer[location].get(), attributes, time,
                              model);
}

void TraceWriter::handleThreadTeamBeginEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_CommRef threadTeam) {
    OTF2_EvtWriter_ThreadTeamBegin(m_event_writer[location].get(), attributes,
                                   time, threadTeam);
}

void TraceWriter::handleThreadTeamEndEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_CommRef threadTeam) {
    OTF2_EvtWriter_ThreadTeamEnd(m_event_writer[location].get(), attributes,
                                 time, threadTeam);
}

void TraceWriter::handleThreadAcquireLockEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_Paradigm model,
                                               uint32_t lockID,
                                               uint32_t acquisitionOrder) {
    OTF2_EvtWriter_ThreadAcquireLock(m_event_writer[location].get(), attributes,
                                     time, model, lockID, acquisitionOrder);
}

void TraceWriter::handleThreadReleaseLockEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_Paradigm model,
                                               uint32_t lockID,
                                               uint32_t acquisitionOrder) {
    OTF2_EvtWriter_ThreadReleaseLock(m_event_writer[location].get(), attributes,
                                     time, model, lockID, acquisitionOrder);
}

void TraceWriter::handleThreadTaskCreateEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              OTF2_CommRef threadTeam,
                                              uint32_t creatingThread,
                                              uint32_t generationNumber) {
    OTF2_EvtWriter_ThreadTaskCreate(m_event_writer[location].get(), attributes,
                                    time, threadTeam, creatingThread,
                                    generationNumber);
}

void TraceWriter::handleThreadTaskSwitchEvent(OTF2_LocationRef location,
                                              OTF2_TimeStamp time,
                                              OTF2_AttributeList *attributes,
                                              OTF2_CommRef threadTeam,
                                              uint32_t creatingThread,
                                              uint32_t generationNumber) {
    OTF2_EvtWriter_ThreadTaskSwitch(m_event_writer[location].get(), attributes,
                                    time, threadTeam, creatingThread,
                                    generationNumber);
}

void TraceWriter::handleThreadTaskCompleteEvent(OTF2_LocationRef location,
                                                OTF2_TimeStamp time,
                                                OTF2_AttributeList *attributes,
                                                OTF2_CommRef threadTeam,
                                                uint32_t creatingThread,
                                                uint32_t generationNumber) {
    OTF2_EvtWriter_ThreadTaskComplete(m_event_writer[location].get(),
                                      attributes, time, threadTeam,
                                      creatingThread, generationNumber);
}

void TraceWriter::handleThreadCreateEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_CommRef threadContingent,
                                          uint64_t sequenceCount) {
    OTF2_EvtWriter_ThreadCreate(m_event_writer[location].get(), attributes,
                                time, threadContingent, sequenceCount);
}

void TraceWriter::handleThreadBeginEvent(OTF2_LocationRef location,
                                         OTF2_TimeStamp time,
                                         OTF2_AttributeList *attributes,
                                         OTF2_CommRef threadContingent,
                                         uint64_t sequenceCount) {
    OTF2_EvtWriter_ThreadBegin(m_event_writer[location].get(), attributes, time,
                               threadContingent, sequenceCount);
}

void TraceWriter::handleThreadWaitEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        OTF2_CommRef threadContingent,
                                        uint64_t sequenceCount) {
    OTF2_EvtWriter_ThreadWait(m_event_writer[location].get(), attributes, time,
                              threadContingent, sequenceCount);
}

void TraceWriter::handleThreadEndEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_CommRef threadContingent,
                                       uint64_t sequenceCount) {
    OTF2_EvtWriter_ThreadEnd(m_event_writer[location].get(), attributes, time,
                             threadContingent, sequenceCount);
}

void TraceWriter::handleCallingContextEnterEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
    uint32_t unwindDistance) {
    OTF2_EvtWriter_CallingContextEnter(m_event_writer[location].get(),
                                       attributes, time, callingContext,
                                       unwindDistance);
}

void TraceWriter::handleCallingContextLeaveEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext) {
    OTF2_EvtWriter_CallingContextLeave(m_event_writer[location].get(),
                                       attributes, time, callingContext);
}

void TraceWriter::handleCallingContextSampleEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_CallingContextRef callingContext,
    uint32_t unwindDistance, OTF2_InterruptGeneratorRef interruptGenerator) {
    OTF2_EvtWriter_CallingContextSample(m_event_writer[location].get(),
                                        attributes, time, callingContext,
                                        unwindDistance, interruptGenerator);
}

void TraceWriter::handleIoCreateHandleEvent(OTF2_LocationRef location,
                                            OTF2_TimeStamp time,
                                            OTF2_AttributeList *attributes,
                                            OTF2_IoHandleRef handle,
                                            OTF2_IoAccessMode mode,
                                            OTF2_IoCreationFlag creationFlags,
                                            OTF2_IoStatusFlag statusFlags) {
    OTF2_EvtWriter_IoCreateHandle(m_event_writer[location].get(), attributes,
                                  time, handle, mode, creationFlags,
                                  statusFlags);
}

void TraceWriter::handleIoDestroyHandleEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoHandleRef handle) {
    OTF2_EvtWriter_IoDestroyHandle(m_event_writer[location].get(), attributes,
                                   time, handle);
}

void TraceWriter::handleIoDuplicateHandleEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_IoHandleRef oldHandle,
                                               OTF2_IoHandleRef newHandle,
                                               OTF2_IoStatusFlag statusFlags) {
    OTF2_EvtWriter_IoDuplicateHandle(m_event_writer[location].get(), attributes,
                                     time, oldHandle, newHandle, statusFlags);
}

void TraceWriter::handleIoSeekEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    int64_t offsetRequest, OTF2_IoSeekOption whence, uint64_t offsetResult) {
    OTF2_EvtWriter_IoSeek(m_event_writer[location].get(), attributes, time,
                          handle, offsetRequest, whence, offsetResult);
}

void TraceWriter::handleIoChangeStatusFlagsEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    OTF2_IoStatusFlag statusFlags) {
    OTF2_EvtWriter_IoChangeStatusFlags(m_event_writer[location].get(),
                                       attributes, time, handle, statusFlags);
}

void TraceWriter::handleIoDeleteFileEvent(OTF2_LocationRef location,
                                          OTF2_TimeStamp time,
                                          OTF2_AttributeList *attributes,
                                          OTF2_IoParadigmRef ioParadigm,
                                          OTF2_IoFileRef file) {
    OTF2_EvtWriter_IoDeleteFile(m_event_writer[location].get(), attributes,
                                time, ioParadigm, file);
}

void TraceWriter::handleIoOperationBeginEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    OTF2_IoOperationMode mode, OTF2_IoOperationFlag operationFlags,
    uint64_t bytesRequest, uint64_t matchingId) {
    OTF2_EvtWriter_IoOperationBegin(m_event_writer[location].get(), attributes,
                                    time, handle, mode, operationFlags,
                                    bytesRequest, matchingId);
}

void TraceWriter::handleIoOperationTestEvent(OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoHandleRef handle,
                                             uint64_t matchingId) {
    OTF2_EvtWriter_IoOperationTest(m_event_writer[location].get(), attributes,
                                   time, handle, matchingId);
}

void TraceWriter::handleIoOperationIssuedEvent(OTF2_LocationRef location,
                                               OTF2_TimeStamp time,
                                               OTF2_AttributeList *attributes,
                                               OTF2_IoHandleRef handle,
                                               uint64_t matchingId) {
    OTF2_EvtWriter_IoOperationIssued(m_event_writer[location].get(), attributes,
                                     time, handle, matchingId);
}

void TraceWriter::handleIoOperationCompleteEvent(OTF2_LocationRef location,
                                                 OTF2_TimeStamp time,
                                                 OTF2_AttributeList *attributes,
                                                 OTF2_IoHandleRef handle,
                                                 uint64_t bytesResult,
                                                 uint64_t matchingId) {
    OTF2_EvtWriter_IoOperationComplete(m_event_writer[location].get(),
                                       attributes, time, handle, bytesResult,
                                       matchingId);
}

void TraceWriter::handleIoOperationCancelledEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_IoHandleRef handle,
    uint64_t matchingId) {
    OTF2_EvtWriter_IoOperationCancelled(m_event_writer[location].get(),
                                        attributes, time, handle, matchingId);
}

void TraceWriter::handleIoAcquireLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle,
                                           OTF2_LockType lockType) {
    OTF2_EvtWriter_IoAcquireLock(m_event_writer[location].get(), attributes,
                                 time, handle, lockType);
}

void TraceWriter::handleIoReleaseLockEvent(OTF2_LocationRef location,
                                           OTF2_TimeStamp time,
                                           OTF2_AttributeList *attributes,
                                           OTF2_IoHandleRef handle,
                                           OTF2_LockType lockType) {
    OTF2_EvtWriter_IoReleaseLock(m_event_writer[location].get(), attributes,
                                 time, handle, lockType);
}

void TraceWriter::handleIoTryLockEvent(OTF2_LocationRef location,
                                       OTF2_TimeStamp time,
                                       OTF2_AttributeList *attributes,
                                       OTF2_IoHandleRef handle,
                                       OTF2_LockType lockType) {
    OTF2_EvtWriter_IoTryLock(m_event_writer[location].get(), attributes, time,
                             handle, lockType);
}

void TraceWriter::handleProgramBeginEvent(
    OTF2_LocationRef location, OTF2_TimeStamp time,
    OTF2_AttributeList *attributes, OTF2_StringRef programName,
    uint32_t numberOfArguments, const OTF2_StringRef *programArguments) {
    OTF2_EvtWriter_ProgramBegin(m_event_writer[location].get(), attributes,
                                time, programName, numberOfArguments,
                                programArguments);
}

void TraceWriter::handleProgramEndEvent(OTF2_LocationRef location,
                                        OTF2_TimeStamp time,
                                        OTF2_AttributeList *attributes,
                                        int64_t exitStatus) {
    OTF2_EvtWriter_ProgramEnd(m_event_writer[location].get(), attributes, time,
                              exitStatus);
}
