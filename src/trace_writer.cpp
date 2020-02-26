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
        OTF2_Archive_CloseEvtFiles(archive);
    }
}

void delete_archive(OTF2_Archive *archive) {
    if (nullptr != archive) {
        OTF2_Archive_Close(archive);
    }
}

TraceWriter::TraceWriter(const std::string &path)
    : m_archive(nullptr, delete_archive),
      m_event_writer(nullptr, [this](OTF2_EvtWriter *writer) {
          delete_event_writer(writer, m_archive.get());
      }) {
    auto *archive =
        OTF2_Archive_Open(path.c_str(), "trace", OTF2_FILEMODE_WRITE,
                          1024 * 1024 /* event chunk size */,
                          4 * 1024 * 1024 /* def chunk size */,
                          OTF2_SUBSTRATE_POSIX, OTF2_COMPRESSION_NONE);

    OTF2_Archive_SetFlushCallbacks(archive, &m_flush_callbacks, nullptr);
    OTF2_Archive_SetSerialCollectiveCallbacks(archive);
    m_archive.reset(archive);

    OTF2_Archive_OpenEvtFiles(archive);
    m_event_writer.reset(OTF2_Archive_GetEvtWriter(archive, 0));

    m_def_writer = OTF2_Archive_GetGlobalDefWriter(archive);
    assert(m_def_writer);
}

TraceWriter::~TraceWriter() {}

void TraceWriter::writeClockProperties(uint64_t timerResolution,
                                       uint64_t globalOffset,
                                       uint64_t traceLength) {
    OTF2_GlobalDefWriter_WriteClockProperties(m_def_writer, timerResolution,
                                              globalOffset, traceLength);
}

void TraceWriter::writeParadigm(OTF2_Paradigm paradigm, OTF2_StringRef name,
                                OTF2_ParadigmClass paradigmClass) {
    OTF2_GlobalDefWriter_WriteParadigm(m_def_writer, paradigm, name,
                                       paradigmClass);
}

void TraceWriter::writeParadigmProperty(OTF2_Paradigm paradigm,
                                        OTF2_ParadigmProperty property,
                                        OTF2_Type type,
                                        OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteParadigmProperty(m_def_writer, paradigm, property,
                                               type, value);
}

void TraceWriter::writeIoParadigm(
    OTF2_IoParadigmRef self, OTF2_StringRef identification, OTF2_StringRef name,
    OTF2_IoParadigmClass ioParadigmClass, OTF2_IoParadigmFlag ioParadigmFlags,
    uint8_t numberOfProperties, const OTF2_IoParadigmProperty *properties,
    const OTF2_Type *types, const OTF2_AttributeValue *values) {
    OTF2_GlobalDefWriter_WriteIoParadigm(
        m_def_writer, self, identification, name, ioParadigmClass,
        ioParadigmFlags, numberOfProperties, properties, types, values);
}

void TraceWriter::writeString(OTF2_StringRef self, const char *string) {
    OTF2_GlobalDefWriter_WriteString(m_def_writer, self, string);
}

void TraceWriter::writeAttribute(OTF2_AttributeRef self, OTF2_StringRef name,
                                 OTF2_StringRef description, OTF2_Type type) {
    OTF2_GlobalDefWriter_WriteAttribute(m_def_writer, self, name, description,
                                        type);
}

void TraceWriter::writeSystemTreeNode(OTF2_SystemTreeNodeRef self,
                                      OTF2_StringRef name,
                                      OTF2_StringRef className,
                                      OTF2_SystemTreeNodeRef parent) {
    OTF2_GlobalDefWriter_WriteSystemTreeNode(m_def_writer, self, name,
                                             className, parent);
}

void TraceWriter::writeLocationGroup(OTF2_LocationGroupRef self,
                                     OTF2_StringRef name,
                                     OTF2_LocationGroupType locationGroupType,
                                     OTF2_SystemTreeNodeRef systemTreeParent) {
    OTF2_GlobalDefWriter_WriteLocationGroup(
        m_def_writer, self, name, locationGroupType, systemTreeParent);
}

void TraceWriter::writeLocation(OTF2_LocationRef self, OTF2_StringRef name,
                                OTF2_LocationType locationType,
                                uint64_t numberOfEvents,
                                OTF2_LocationGroupRef locationGroup) {
    OTF2_GlobalDefWriter_WriteLocation(m_def_writer, self, name, locationType,
                                       numberOfEvents, locationGroup);
}

void TraceWriter::writeRegion(
    OTF2_RegionRef self, OTF2_StringRef name, OTF2_StringRef canonicalName,
    OTF2_StringRef description, OTF2_RegionRole regionRole,
    OTF2_Paradigm paradigm, OTF2_RegionFlag regionFlags,
    OTF2_StringRef sourceFile, uint32_t beginLineNumber,
    uint32_t endLineNumber) {
    OTF2_GlobalDefWriter_WriteRegion(
        m_def_writer, self, name, canonicalName, description, regionRole,
        paradigm, regionFlags, sourceFile, beginLineNumber, endLineNumber);
}

void TraceWriter::writeCallsite(OTF2_CallsiteRef self,
                                OTF2_StringRef sourceFile, uint32_t lineNumber,
                                OTF2_RegionRef enteredRegion,
                                OTF2_RegionRef leftRegion) {
    OTF2_GlobalDefWriter_WriteCallsite(m_def_writer, self, sourceFile,
                                       lineNumber, enteredRegion, leftRegion);
}

void TraceWriter::writeCallpath(OTF2_CallpathRef self, OTF2_CallpathRef parent,
                                OTF2_RegionRef region) {
    OTF2_GlobalDefWriter_WriteCallpath(m_def_writer, self, parent, region);
}

void TraceWriter::writeGroup(OTF2_GroupRef self, OTF2_StringRef name,
                             OTF2_GroupType groupType, OTF2_Paradigm paradigm,
                             OTF2_GroupFlag groupFlags,
                             uint32_t numberOfMembers,
                             const uint64_t *members) {
    OTF2_GlobalDefWriter_WriteGroup(m_def_writer, self, name, groupType,
                                    paradigm, groupFlags, numberOfMembers,
                                    members);
}

void TraceWriter::writeMetricMember(
    OTF2_MetricMemberRef self, OTF2_StringRef name, OTF2_StringRef description,
    OTF2_MetricType metricType, OTF2_MetricMode metricMode, OTF2_Type valueType,
    OTF2_Base base, int64_t exponent, OTF2_StringRef unit) {
    OTF2_GlobalDefWriter_WriteMetricMember(m_def_writer, self, name,
                                           description, metricType, metricMode,
                                           valueType, base, exponent, unit);
}

void TraceWriter::writeMetricClass(OTF2_MetricRef self, uint8_t numberOfMetrics,
                                   const OTF2_MetricMemberRef *metricMembers,
                                   OTF2_MetricOccurrence metricOccurrence,
                                   OTF2_RecorderKind recorderKind) {
    OTF2_GlobalDefWriter_WriteMetricClass(m_def_writer, self, numberOfMetrics,
                                          metricMembers, metricOccurrence,
                                          recorderKind);
}

void TraceWriter::writeMetricInstance(OTF2_MetricRef self,
                                      OTF2_MetricRef metricClass,
                                      OTF2_LocationRef recorder,
                                      OTF2_MetricScope metricScope,
                                      uint64_t scope) {
    OTF2_GlobalDefWriter_WriteMetricInstance(m_def_writer, self, metricClass,
                                             recorder, metricScope, scope);
}

void TraceWriter::writeComm(OTF2_CommRef self, OTF2_StringRef name,
                            OTF2_GroupRef group, OTF2_CommRef parent) {
    OTF2_GlobalDefWriter_WriteComm(m_def_writer, self, name, group, parent);
}

void TraceWriter::writeParameter(OTF2_ParameterRef self, OTF2_StringRef name,
                                 OTF2_ParameterType parameterType) {
    OTF2_GlobalDefWriter_WriteParameter(m_def_writer, self, name,
                                        parameterType);
}

void TraceWriter::writeRmaWin(OTF2_RmaWinRef self, OTF2_StringRef name,
                              OTF2_CommRef comm) {
    OTF2_GlobalDefWriter_WriteRmaWin(m_def_writer, self, name, comm);
}

void TraceWriter::writeMetricClassRecorder(OTF2_MetricRef metric,
                                           OTF2_LocationRef recorder) {
    OTF2_GlobalDefWriter_WriteMetricClassRecorder(m_def_writer, metric,
                                                  recorder);
}

void TraceWriter::writeSystemTreeNodeProperty(
    OTF2_SystemTreeNodeRef systemTreeNode, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteSystemTreeNodeProperty(
        m_def_writer, systemTreeNode, name, type, value);
}

void TraceWriter::writeSystemTreeNodeDomain(
    OTF2_SystemTreeNodeRef systemTreeNode,
    OTF2_SystemTreeDomain systemTreeDomain) {
    OTF2_GlobalDefWriter_WriteSystemTreeNodeDomain(m_def_writer, systemTreeNode,
                                                   systemTreeDomain);
}

void TraceWriter::writeLocationGroupProperty(
    OTF2_LocationGroupRef locationGroup, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteLocationGroupProperty(m_def_writer, locationGroup,
                                                    name, type, value);
}

void TraceWriter::writeLocationProperty(OTF2_LocationRef location,
                                        OTF2_StringRef name, OTF2_Type type,
                                        OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteLocationProperty(m_def_writer, location, name,
                                               type, value);
}

void TraceWriter::writeCartDimension(OTF2_CartDimensionRef self,
                                     OTF2_StringRef name, uint32_t size,
                                     OTF2_CartPeriodicity cartPeriodicity) {
    OTF2_GlobalDefWriter_WriteCartDimension(m_def_writer, self, name, size,
                                            cartPeriodicity);
}

void TraceWriter::writeCartTopology(
    OTF2_CartTopologyRef self, OTF2_StringRef name, OTF2_CommRef communicator,
    uint8_t numberOfDimensions, const OTF2_CartDimensionRef *cartDimensions) {
    OTF2_GlobalDefWriter_WriteCartTopology(m_def_writer, self, name,
                                           communicator, numberOfDimensions,
                                           cartDimensions);
}

void TraceWriter::writeCartCoordinate(OTF2_CartTopologyRef cartTopology,
                                      uint32_t rank, uint8_t numberOfDimensions,
                                      const uint32_t *coordinates) {
    OTF2_GlobalDefWriter_WriteCartCoordinate(m_def_writer, cartTopology, rank,
                                             numberOfDimensions, coordinates);
}

void TraceWriter::writeSourceCodeLocation(OTF2_SourceCodeLocationRef self,
                                          OTF2_StringRef file,
                                          uint32_t lineNumber) {
    OTF2_GlobalDefWriter_WriteSourceCodeLocation(m_def_writer, self, file,
                                                 lineNumber);
}

void TraceWriter::writeCallingContext(
    OTF2_CallingContextRef self, OTF2_RegionRef region,
    OTF2_SourceCodeLocationRef sourceCodeLocation,
    OTF2_CallingContextRef parent) {
    OTF2_GlobalDefWriter_WriteCallingContext(m_def_writer, self, region,
                                             sourceCodeLocation, parent);
}

void TraceWriter::writeCallingContextProperty(
    OTF2_CallingContextRef callingContext, OTF2_StringRef name, OTF2_Type type,
    OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteCallingContextProperty(
        m_def_writer, callingContext, name, type, value);
}

void TraceWriter::writeInterruptGenerator(
    OTF2_InterruptGeneratorRef self, OTF2_StringRef name,
    OTF2_InterruptGeneratorMode interruptGeneratorMode, OTF2_Base base,
    int64_t exponent, uint64_t period) {
    OTF2_GlobalDefWriter_WriteInterruptGenerator(m_def_writer, self, name,
                                                 interruptGeneratorMode, base,
                                                 exponent, period);
}

void TraceWriter::writeIoFileProperty(OTF2_IoFileRef ioFile,
                                      OTF2_StringRef name, OTF2_Type type,
                                      OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteIoFileProperty(m_def_writer, ioFile, name, type,
                                             value);
}

void TraceWriter::writeIoRegularFile(OTF2_IoFileRef self, OTF2_StringRef name,
                                     OTF2_SystemTreeNodeRef scope) {
    OTF2_GlobalDefWriter_WriteIoRegularFile(m_def_writer, self, name, scope);
}

void TraceWriter::writeIoDirectory(OTF2_IoFileRef self, OTF2_StringRef name,
                                   OTF2_SystemTreeNodeRef scope) {
    OTF2_GlobalDefWriter_WriteIoDirectory(m_def_writer, self, name, scope);
}

void TraceWriter::writeIoHandle(OTF2_IoHandleRef self, OTF2_StringRef name,
                                OTF2_IoFileRef file,
                                OTF2_IoParadigmRef ioParadigm,
                                OTF2_IoHandleFlag ioHandleFlags,
                                OTF2_CommRef comm, OTF2_IoHandleRef parent) {
    OTF2_GlobalDefWriter_WriteIoHandle(m_def_writer, self, name, file,
                                       ioParadigm, ioHandleFlags, comm, parent);
}

void TraceWriter::writeIoPreCreatedHandleState(OTF2_IoHandleRef ioHandle,
                                               OTF2_IoAccessMode mode,
                                               OTF2_IoStatusFlag statusFlags) {
    OTF2_GlobalDefWriter_WriteIoPreCreatedHandleState(m_def_writer, ioHandle,
                                                      mode, statusFlags);
}

void TraceWriter::writeCallpathParameter(OTF2_CallpathRef callpath,
                                         OTF2_ParameterRef parameter,
                                         OTF2_Type type,
                                         OTF2_AttributeValue value) {
    OTF2_GlobalDefWriter_WriteCallpathParameter(m_def_writer, callpath,
                                                parameter, type, value);
}

/* void
TraceWriter::writerEnterEvent(OTF2_LocationRef    location,
                              OTF2_AttributeList * attributeList,
                              OTF2_TimeStamp  	   time,
                              OTF2_RegionRef  	   region)
{
    auto writer = OTF2_Archive_GetEvtWriter(m_archive.get(), location);
    OTF2_EvtWriter_Enter(writer,
                         attributeList,
                         time,
                         region);
}

void
TraceWriter::writerLeaveEvent(OTF2_LocationRef    location,
                              OTF2_AttributeList * attributeList,
                              OTF2_TimeStamp  	   time,
                              OTF2_RegionRef  	   region)
{
    auto writer = OTF2_Archive_GetEvtWriter(m_archive.get(), location);
    OTF2_EvtWriter_Leave(writer,
                         attributeList,
                         time,
                         region);
}*/