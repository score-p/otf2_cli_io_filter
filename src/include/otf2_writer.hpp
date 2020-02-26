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
};

#endif /* OTF2_WRITER_H */