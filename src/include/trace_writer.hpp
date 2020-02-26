#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <functional>
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

  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    event_writer_ptr m_event_writer;
    OTF2_GlobalDefWriter *m_def_writer;
};

#endif /* TRACE_WRITER_H */