#ifndef DEFINITION_CALLBACKS_HPP
#define DEFINITION_CALLBACKS_HPP

extern "C" {
#include <otf2/otf2.h>
}

namespace definition {

OTF2_CallbackCode ClockPropertiesCb(void *userData, uint64_t timerResolution,
                                    uint64_t globalOffset,
                                    uint64_t traceLength);

OTF2_CallbackCode ParadigmCb(void *userData, OTF2_Paradigm paradigm,
                             OTF2_StringRef name,
                             OTF2_ParadigmClass paradigmClass);

OTF2_CallbackCode ParadigmPropertyCb(void *userData, OTF2_Paradigm paradigm,
                                     OTF2_ParadigmProperty property,
                                     OTF2_Type type, OTF2_AttributeValue value);

OTF2_CallbackCode
IoParadigmCb(void *userData, OTF2_IoParadigmRef self,
             OTF2_StringRef identification, OTF2_StringRef name,
             OTF2_IoParadigmClass ioParadigmClass,
             OTF2_IoParadigmFlag ioParadigmFlags, uint8_t numberOfProperties,
             const OTF2_IoParadigmProperty *properties, const OTF2_Type *types,
             const OTF2_AttributeValue *values);

OTF2_CallbackCode StringCb(void *userData, OTF2_StringRef self,
                           const char *string);

OTF2_CallbackCode AttributeCb(void *userData, OTF2_AttributeRef self,
                              OTF2_StringRef name, OTF2_StringRef description,
                              OTF2_Type type);

OTF2_CallbackCode SystemTreeNodeCb(void *userData, OTF2_SystemTreeNodeRef self,
                                   OTF2_StringRef name,
                                   OTF2_StringRef className,
                                   OTF2_SystemTreeNodeRef parent);

OTF2_CallbackCode LocationGroupCb(void *userData, OTF2_LocationGroupRef self,
                                  OTF2_StringRef name,
                                  OTF2_LocationGroupType locationGroupType,
                                  OTF2_SystemTreeNodeRef systemTreeParent);

OTF2_CallbackCode LocationCb(void *userData, OTF2_LocationRef self,
                             OTF2_StringRef name,
                             OTF2_LocationType locationType,
                             uint64_t numberOfEvents,
                             OTF2_LocationGroupRef locationGroup);

OTF2_CallbackCode RegionCb(void *userData, OTF2_RegionRef self,
                           OTF2_StringRef name, OTF2_StringRef canonicalName,
                           OTF2_StringRef description,
                           OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                           OTF2_RegionFlag regionFlags,
                           OTF2_StringRef sourceFile, uint32_t beginLineNumber,
                           uint32_t endLineNumber);

OTF2_CallbackCode CallsiteCb(void *userData, OTF2_CallsiteRef self,
                             OTF2_StringRef sourceFile, uint32_t lineNumber,
                             OTF2_RegionRef enteredRegion,
                             OTF2_RegionRef leftRegion);

OTF2_CallbackCode CallpathCb(void *userData, OTF2_CallpathRef self,
                             OTF2_CallpathRef parent, OTF2_RegionRef region);

OTF2_CallbackCode GroupCb(void *userData, OTF2_GroupRef self,
                          OTF2_StringRef name, OTF2_GroupType groupType,
                          OTF2_Paradigm paradigm, OTF2_GroupFlag groupFlags,
                          uint32_t numberOfMembers, const uint64_t *members);

OTF2_CallbackCode
MetricMemberCb(void *userData, OTF2_MetricMemberRef self, OTF2_StringRef name,
               OTF2_StringRef description, OTF2_MetricType metricType,
               OTF2_MetricMode metricMode, OTF2_Type valueType, OTF2_Base base,
               int64_t exponent, OTF2_StringRef unit);

OTF2_CallbackCode MetricClassCb(void *userData, OTF2_MetricRef self,
                                uint8_t numberOfMetrics,
                                const OTF2_MetricMemberRef *metricMembers,
                                OTF2_MetricOccurrence metricOccurrence,
                                OTF2_RecorderKind recorderKind);

OTF2_CallbackCode MetricInstanceCb(void *userData, OTF2_MetricRef self,
                                   OTF2_MetricRef metricClass,
                                   OTF2_LocationRef recorder,
                                   OTF2_MetricScope metricScope,
                                   uint64_t scope);

OTF2_CallbackCode CommCb(void *userData, OTF2_CommRef self, OTF2_StringRef name,
                         OTF2_GroupRef group, OTF2_CommRef parent);

OTF2_CallbackCode ParameterCb(void *userData, OTF2_ParameterRef self,
                              OTF2_StringRef name,
                              OTF2_ParameterType parameterType);

OTF2_CallbackCode RmaWinCb(void *userData, OTF2_RmaWinRef self,
                           OTF2_StringRef name, OTF2_CommRef comm);

OTF2_CallbackCode MetricClassRecorderCb(void *userData, OTF2_MetricRef metric,
                                        OTF2_LocationRef recorder);

OTF2_CallbackCode
SystemTreeNodePropertyCb(void *userData, OTF2_SystemTreeNodeRef systemTreeNode,
                         OTF2_StringRef name, OTF2_Type type,
                         OTF2_AttributeValue value);

OTF2_CallbackCode
SystemTreeNodeDomainCb(void *userData, OTF2_SystemTreeNodeRef systemTreeNode,
                       OTF2_SystemTreeDomain systemTreeDomain);

OTF2_CallbackCode LocationGroupPropertyCb(void *userData,
                                          OTF2_LocationGroupRef locationGroup,
                                          OTF2_StringRef name, OTF2_Type type,
                                          OTF2_AttributeValue value);

OTF2_CallbackCode LocationPropertyCb(void *userData, OTF2_LocationRef location,
                                     OTF2_StringRef name, OTF2_Type type,
                                     OTF2_AttributeValue value);

OTF2_CallbackCode CartDimensionCb(void *userData, OTF2_CartDimensionRef self,
                                  OTF2_StringRef name, uint32_t size,
                                  OTF2_CartPeriodicity cartPeriodicity);

OTF2_CallbackCode CartTopologyCb(void *userData, OTF2_CartTopologyRef self,
                                 OTF2_StringRef name, OTF2_CommRef communicator,
                                 uint8_t numberOfDimensions,
                                 const OTF2_CartDimensionRef *cartDimensions);

OTF2_CallbackCode CartCoordinateCb(void *userData,
                                   OTF2_CartTopologyRef cartTopology,
                                   uint32_t rank, uint8_t numberOfDimensions,
                                   const uint32_t *coordinates);

OTF2_CallbackCode SourceCodeLocationCb(void *userData,
                                       OTF2_SourceCodeLocationRef self,
                                       OTF2_StringRef file,
                                       uint32_t lineNumber);

OTF2_CallbackCode
CallingContextCb(void *userData, OTF2_CallingContextRef self,
                 OTF2_RegionRef region,
                 OTF2_SourceCodeLocationRef sourceCodeLocation,
                 OTF2_CallingContextRef parent);

OTF2_CallbackCode
CallingContextPropertyCb(void *userData, OTF2_CallingContextRef callingContext,
                         OTF2_StringRef name, OTF2_Type type,
                         OTF2_AttributeValue value);

OTF2_CallbackCode
InterruptGeneratorCb(void *userData, OTF2_InterruptGeneratorRef self,
                     OTF2_StringRef name,
                     OTF2_InterruptGeneratorMode interruptGeneratorMode,
                     OTF2_Base base, int64_t exponent, uint64_t period);

OTF2_CallbackCode IoFilePropertyCb(void *userData, OTF2_IoFileRef ioFile,
                                   OTF2_StringRef name, OTF2_Type type,
                                   OTF2_AttributeValue value);

OTF2_CallbackCode IoRegularFileCb(void *userData, OTF2_IoFileRef self,
                                  OTF2_StringRef name,
                                  OTF2_SystemTreeNodeRef scope);

OTF2_CallbackCode IoDirectoryCb(void *userData, OTF2_IoFileRef self,
                                OTF2_StringRef name,
                                OTF2_SystemTreeNodeRef scope);

OTF2_CallbackCode IoHandleCb(void *userData, OTF2_IoHandleRef self,
                             OTF2_StringRef name, OTF2_IoFileRef file,
                             OTF2_IoParadigmRef ioParadigm,
                             OTF2_IoHandleFlag ioHandleFlags, OTF2_CommRef comm,
                             OTF2_IoHandleRef parent);

OTF2_CallbackCode IoPreCreatedHandleStateCb(void *userData,
                                            OTF2_IoHandleRef ioHandle,
                                            OTF2_IoAccessMode mode,
                                            OTF2_IoStatusFlag statusFlags);

OTF2_CallbackCode CallpathParameterCb(void *userData, OTF2_CallpathRef callpath,
                                      OTF2_ParameterRef parameter,
                                      OTF2_Type type,
                                      OTF2_AttributeValue value);

} // namespace definition

#endif /* DEFINITION_CALLBACKS_HPP */