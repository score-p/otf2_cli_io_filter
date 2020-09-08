#include <global_callbacks.hpp>
#include <trace_reader.hpp>

namespace definition
{

OTF2_CallbackCode
GlobalClockPropertiesCb(void *userData, uint64_t timerResolution, uint64_t globalOffset, uint64_t traceLength)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalClockProperties(timerResolution, globalOffset, traceLength);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalParadigmCb(void *userData, OTF2_Paradigm paradigm, OTF2_StringRef name, OTF2_ParadigmClass paradigmClass)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalParadigm(paradigm, name, paradigmClass);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalParadigmPropertyCb(
    void *userData, OTF2_Paradigm paradigm, OTF2_ParadigmProperty property, OTF2_Type type, OTF2_AttributeValue value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalParadigmProperty(paradigm, property, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoParadigmCb(void *                         userData,
                   OTF2_IoParadigmRef             self,
                   OTF2_StringRef                 identification,
                   OTF2_StringRef                 name,
                   OTF2_IoParadigmClass           ioParadigmClass,
                   OTF2_IoParadigmFlag            ioParadigmFlags,
                   uint8_t                        numberOfProperties,
                   const OTF2_IoParadigmProperty *properties,
                   const OTF2_Type *              types,
                   const OTF2_AttributeValue *    values)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoParadigm(
        self, identification, name, ioParadigmClass, ioParadigmFlags, numberOfProperties, properties, types, values);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalStringCb(void *userData, OTF2_StringRef self, const char *string)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalString(self, string);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalAttributeCb(
    void *userData, OTF2_AttributeRef self, OTF2_StringRef name, OTF2_StringRef description, OTF2_Type type)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalAttribute(self, name, description, type);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalSystemTreeNodeCb(void *                 userData,
                       OTF2_SystemTreeNodeRef self,
                       OTF2_StringRef         name,
                       OTF2_StringRef         className,
                       OTF2_SystemTreeNodeRef parent)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalSystemTreeNode(self, name, className, parent);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalLocationGroupCb(void *                 userData,
                      OTF2_LocationGroupRef  self,
                      OTF2_StringRef         name,
                      OTF2_LocationGroupType locationGroupType,
                      OTF2_SystemTreeNodeRef systemTreeParent)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalLocationGroup(self, name, locationGroupType, systemTreeParent);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalLocationCb(void *                userData,
                 OTF2_LocationRef      self,
                 OTF2_StringRef        name,
                 OTF2_LocationType     locationType,
                 uint64_t              numberOfEvents,
                 OTF2_LocationGroupRef locationGroup)
{
    auto tr = static_cast<TraceReader *>(userData);
    if (tr->m_locations.size() == tr->m_location_count)
    {
        return OTF2_CALLBACK_INTERRUPT;
    }
    tr->m_locations.push_back(self);
    tr->handler().handleGlobalLocation(self, name, locationType, numberOfEvents, locationGroup);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalRegionCb(void *          userData,
               OTF2_RegionRef  self,
               OTF2_StringRef  name,
               OTF2_StringRef  canonicalName,
               OTF2_StringRef  description,
               OTF2_RegionRole regionRole,
               OTF2_Paradigm   paradigm,
               OTF2_RegionFlag regionFlags,
               OTF2_StringRef  sourceFile,
               uint32_t        beginLineNumber,
               uint32_t        endLineNumber)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalRegion(self,
                                     name,
                                     canonicalName,
                                     description,
                                     regionRole,
                                     paradigm,
                                     regionFlags,
                                     sourceFile,
                                     beginLineNumber,
                                     endLineNumber);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCallsiteCb(void *           userData,
                 OTF2_CallsiteRef self,
                 OTF2_StringRef   sourceFile,
                 uint32_t         lineNumber,
                 OTF2_RegionRef   enteredRegion,
                 OTF2_RegionRef   leftRegion)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCallsite(self, sourceFile, lineNumber, enteredRegion, leftRegion);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCallpathCb(void *userData, OTF2_CallpathRef self, OTF2_CallpathRef parent, OTF2_RegionRef region)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCallpath(self, parent, region);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalGroupCb(void *          userData,
              OTF2_GroupRef   self,
              OTF2_StringRef  name,
              OTF2_GroupType  groupType,
              OTF2_Paradigm   paradigm,
              OTF2_GroupFlag  groupFlags,
              uint32_t        numberOfMembers,
              const uint64_t *members)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalGroup(self, name, groupType, paradigm, groupFlags, numberOfMembers, members);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalMetricMemberCb(void *               userData,
                     OTF2_MetricMemberRef self,
                     OTF2_StringRef       name,
                     OTF2_StringRef       description,
                     OTF2_MetricType      metricType,
                     OTF2_MetricMode      metricMode,
                     OTF2_Type            valueType,
                     OTF2_Base            base,
                     int64_t              exponent,
                     OTF2_StringRef       unit)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalMetricMember(
        self, name, description, metricType, metricMode, valueType, base, exponent, unit);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalMetricClassCb(void *                      userData,
                    OTF2_MetricRef              self,
                    uint8_t                     numberOfMetrics,
                    const OTF2_MetricMemberRef *metricMembers,
                    OTF2_MetricOccurrence       metricOccurrence,
                    OTF2_RecorderKind           recorderKind)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalMetricClass(self, numberOfMetrics, metricMembers, metricOccurrence, recorderKind);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalMetricInstanceCb(void *           userData,
                       OTF2_MetricRef   self,
                       OTF2_MetricRef   metricClass,
                       OTF2_LocationRef recorder,
                       OTF2_MetricScope metricScope,
                       uint64_t         scope)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalMetricInstance(self, metricClass, recorder, metricScope, scope);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCommCb(void *userData, OTF2_CommRef self, OTF2_StringRef name, OTF2_GroupRef group, OTF2_CommRef parent)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalComm(self, name, group, parent);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalParameterCb(void *userData, OTF2_ParameterRef self, OTF2_StringRef name, OTF2_ParameterType parameterType)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalParameter(self, name, parameterType);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalRmaWinCb(void *userData, OTF2_RmaWinRef self, OTF2_StringRef name, OTF2_CommRef comm)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalRmaWin(self, name, comm);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalMetricClassRecorderCb(void *userData, OTF2_MetricRef metric, OTF2_LocationRef recorder)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalMetricClassRecorder(metric, recorder);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalSystemTreeNodePropertyCb(void *                 userData,
                               OTF2_SystemTreeNodeRef systemTreeNode,
                               OTF2_StringRef         name,
                               OTF2_Type              type,
                               OTF2_AttributeValue    value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalSystemTreeNodeProperty(systemTreeNode, name, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalSystemTreeNodeDomainCb(void *                 userData,
                             OTF2_SystemTreeNodeRef systemTreeNode,
                             OTF2_SystemTreeDomain  systemTreeDomain)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalSystemTreeNodeDomain(systemTreeNode, systemTreeDomain);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalLocationGroupPropertyCb(
    void *userData, OTF2_LocationGroupRef locationGroup, OTF2_StringRef name, OTF2_Type type, OTF2_AttributeValue value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalLocationGroupProperty(locationGroup, name, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalLocationPropertyCb(
    void *userData, OTF2_LocationRef location, OTF2_StringRef name, OTF2_Type type, OTF2_AttributeValue value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalLocationProperty(location, name, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCartDimensionCb(void *                userData,
                      OTF2_CartDimensionRef self,
                      OTF2_StringRef        name,
                      uint32_t              size,
                      OTF2_CartPeriodicity  cartPeriodicity)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCartDimension(self, name, size, cartPeriodicity);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCartTopologyCb(void *                       userData,
                     OTF2_CartTopologyRef         self,
                     OTF2_StringRef               name,
                     OTF2_CommRef                 communicator,
                     uint8_t                      numberOfDimensions,
                     const OTF2_CartDimensionRef *cartDimensions)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCartTopology(self, name, communicator, numberOfDimensions, cartDimensions);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCartCoordinateCb(void *               userData,
                       OTF2_CartTopologyRef cartTopology,
                       uint32_t             rank,
                       uint8_t              numberOfDimensions,
                       const uint32_t *     coordinates)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCartCoordinate(cartTopology, rank, numberOfDimensions, coordinates);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalSourceCodeLocationCb(void *userData, OTF2_SourceCodeLocationRef self, OTF2_StringRef file, uint32_t lineNumber)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalSourceCodeLocation(self, file, lineNumber);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCallingContextCb(void *                     userData,
                       OTF2_CallingContextRef     self,
                       OTF2_RegionRef             region,
                       OTF2_SourceCodeLocationRef sourceCodeLocation,
                       OTF2_CallingContextRef     parent)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCallingContext(self, region, sourceCodeLocation, parent);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCallingContextPropertyCb(void *                 userData,
                               OTF2_CallingContextRef callingContext,
                               OTF2_StringRef         name,
                               OTF2_Type              type,
                               OTF2_AttributeValue    value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCallingContextProperty(callingContext, name, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalInterruptGeneratorCb(void *                      userData,
                           OTF2_InterruptGeneratorRef  self,
                           OTF2_StringRef              name,
                           OTF2_InterruptGeneratorMode interruptGeneratorMode,
                           OTF2_Base                   base,
                           int64_t                     exponent,
                           uint64_t                    period)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalInterruptGenerator(self, name, interruptGeneratorMode, base, exponent, period);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoFilePropertyCb(
    void *userData, OTF2_IoFileRef ioFile, OTF2_StringRef name, OTF2_Type type, OTF2_AttributeValue value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoFileProperty(ioFile, name, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoRegularFileCb(void *userData, OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoRegularFile(self, name, scope);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoDirectoryCb(void *userData, OTF2_IoFileRef self, OTF2_StringRef name, OTF2_SystemTreeNodeRef scope)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoDirectory(self, name, scope);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoHandleCb(void *             userData,
                 OTF2_IoHandleRef   self,
                 OTF2_StringRef     name,
                 OTF2_IoFileRef     file,
                 OTF2_IoParadigmRef ioParadigm,
                 OTF2_IoHandleFlag  ioHandleFlags,
                 OTF2_CommRef       comm,
                 OTF2_IoHandleRef   parent)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoHandle(self, name, file, ioParadigm, ioHandleFlags, comm, parent);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalIoPreCreatedHandleStateCb(void *            userData,
                                OTF2_IoHandleRef  ioHandle,
                                OTF2_IoAccessMode mode,
                                OTF2_IoStatusFlag statusFlags)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalIoPreCreatedHandleState(ioHandle, mode, statusFlags);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
GlobalCallpathParameterCb(
    void *userData, OTF2_CallpathRef callpath, OTF2_ParameterRef parameter, OTF2_Type type, OTF2_AttributeValue value)
{
    auto tr = static_cast<TraceReader *>(userData);
    tr->handler().handleGlobalCallpathParameter(callpath, parameter, type, value);
    return OTF2_CALLBACK_SUCCESS;
}

} // namespace definition