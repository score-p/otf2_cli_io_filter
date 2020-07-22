#pragma once

#include <functional>
#include <iostream>
#include <vector>

extern "C" {
#include <otf2/otf2.h>
}

template <typename... ArgTypes>
using FilterCallback = std::function<bool(ArgTypes... args)>;

/*
 *  global definition filter
 */

using GlobalClockPropertiesFilter =
    FilterCallback<uint64_t, uint64_t, uint64_t>;

using GlobalParadigmFilter =
    FilterCallback<OTF2_Paradigm, OTF2_StringRef, OTF2_ParadigmClass>;

using GlobalParadigmPropertyFilter =
    FilterCallback<OTF2_Paradigm, OTF2_ParadigmProperty, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalIoParadigmFilter =
    FilterCallback<OTF2_IoParadigmRef, OTF2_StringRef, OTF2_StringRef,
                   OTF2_IoParadigmClass, OTF2_IoParadigmFlag, uint8_t,
                   const OTF2_IoParadigmProperty *, const OTF2_Type *,
                   const OTF2_AttributeValue *>;

using GlobalStringFilter = FilterCallback<OTF2_StringRef, const char *>;

using GlobalAttributeFilter = FilterCallback<OTF2_AttributeRef, OTF2_StringRef,
                                             OTF2_StringRef, OTF2_Type>;

using GlobalSystemTreeNodeFilter =
    FilterCallback<OTF2_SystemTreeNodeRef, OTF2_StringRef, OTF2_StringRef,
                   OTF2_SystemTreeNodeRef>;

using GlobalLocationGroupFilter =
    FilterCallback<OTF2_LocationGroupRef, OTF2_StringRef,
                   OTF2_LocationGroupType, OTF2_SystemTreeNodeRef>;

using GlobalLocationFilter =
    FilterCallback<OTF2_LocationRef, OTF2_StringRef, OTF2_LocationType,
                   uint64_t, OTF2_LocationGroupRef>;

using GlobalRegionFilter =
    FilterCallback<OTF2_RegionRef, OTF2_StringRef, OTF2_StringRef,
                   OTF2_StringRef, OTF2_RegionRole, OTF2_Paradigm,
                   OTF2_RegionFlag, OTF2_StringRef, uint32_t, uint32_t>;

using GlobalCallsiteFilter =
    FilterCallback<OTF2_CallsiteRef, OTF2_StringRef, uint32_t, OTF2_RegionRef,
                   OTF2_RegionRef>;

using GlobalCallpathFilter =
    FilterCallback<OTF2_CallpathRef, OTF2_CallpathRef, OTF2_RegionRef>;

using GlobalGroupFilter =
    FilterCallback<OTF2_GroupRef, OTF2_StringRef, OTF2_GroupType, OTF2_Paradigm,
                   OTF2_GroupFlag, uint32_t, const uint64_t *>;

using GlobalMetricMemberFilter =
    FilterCallback<OTF2_MetricMemberRef, OTF2_StringRef, OTF2_StringRef,
                   OTF2_MetricType, OTF2_MetricMode, OTF2_Type, OTF2_Base,
                   int64_t, OTF2_StringRef>;

using GlobalMetricClassFilter =
    FilterCallback<OTF2_MetricRef, uint8_t, const OTF2_MetricMemberRef *,
                   OTF2_MetricOccurrence, OTF2_RecorderKind>;

using GlobalMetricInstanceFilter =
    FilterCallback<OTF2_MetricRef, OTF2_MetricRef, OTF2_LocationRef,
                   OTF2_MetricScope, uint64_t>;

using GlobalCommFilter =
    FilterCallback<OTF2_CommRef, OTF2_StringRef, OTF2_GroupRef, OTF2_CommRef>;

using GlobalParameterFilter =
    FilterCallback<OTF2_ParameterRef, OTF2_StringRef, OTF2_ParameterType>;

using GlobalRmaWinFilter =
    FilterCallback<OTF2_RmaWinRef, OTF2_StringRef, OTF2_CommRef>;

using GlobalMetricClassRecorderFilter =
    FilterCallback<OTF2_MetricRef, OTF2_LocationRef>;

using GlobalSystemTreeNodePropertyFilter =
    FilterCallback<OTF2_SystemTreeNodeRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalSystemTreeNodeDomainFilter =
    FilterCallback<OTF2_SystemTreeNodeRef, OTF2_SystemTreeDomain>;

using GlobalLocationGroupPropertyFilter =
    FilterCallback<OTF2_LocationGroupRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalLocationPropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalCartDimensionFilter =
    FilterCallback<OTF2_CartDimensionRef, OTF2_StringRef, uint32_t,
                   OTF2_CartPeriodicity>;

using GlobalCartTopologyFilter =
    FilterCallback<OTF2_CartTopologyRef, OTF2_StringRef, OTF2_CommRef, uint8_t,
                   const OTF2_CartDimensionRef *>;

using GlobalCartCoordinateFilter =
    FilterCallback<OTF2_CartTopologyRef, uint32_t, uint8_t, const uint32_t *>;

using GlobalSourceCodeLocationFilter =
    FilterCallback<OTF2_SourceCodeLocationRef, OTF2_StringRef, uint32_t>;

using GlobalCallingContextFilter =
    FilterCallback<OTF2_CallingContextRef, OTF2_RegionRef,
                   OTF2_SourceCodeLocationRef, OTF2_CallingContextRef>;

using GlobalCallingContextPropertyFilter =
    FilterCallback<OTF2_CallingContextRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalInterruptGeneratorFilter =
    FilterCallback<OTF2_InterruptGeneratorRef, OTF2_StringRef,
                   OTF2_InterruptGeneratorMode, OTF2_Base, int64_t, uint64_t>;

using GlobalIoFilePropertyFilter =
    FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using GlobalIoRegularFileFilter =
    FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using GlobalIoDirectoryFilter =
    FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using GlobalIoHandleFilter =
    FilterCallback<OTF2_IoHandleRef, OTF2_StringRef, OTF2_IoFileRef,
                   OTF2_IoParadigmRef, OTF2_IoHandleFlag, OTF2_CommRef,
                   OTF2_IoHandleRef>;

using GlobalIoPreCreatedHandleStateFilter =
    FilterCallback<OTF2_IoHandleRef, OTF2_IoAccessMode, OTF2_IoStatusFlag>;

using GlobalCallpathParameterFilter =
    FilterCallback<OTF2_CallpathRef, OTF2_ParameterRef, OTF2_Type,
                   OTF2_AttributeValue>;

/*
 *  local definition filter
 */

using LocalMappingTableFilter =
    FilterCallback<OTF2_LocationRef, OTF2_MappingType, const OTF2_IdMap *>;

using LocalClockOffsetFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, int64_t, double>;

using LocalStringFilter =
    FilterCallback<OTF2_LocationRef, OTF2_StringRef, const char *>;

using LocalAttributeFilter =
    FilterCallback<OTF2_LocationRef, OTF2_AttributeRef, OTF2_StringRef,
                   OTF2_StringRef, OTF2_Type>;

using LocalSystemTreeNodeFilter =
    FilterCallback<OTF2_LocationRef, OTF2_SystemTreeNodeRef, OTF2_StringRef,
                   OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using LocalLocationGroupFilter =
    FilterCallback<OTF2_LocationRef, OTF2_LocationGroupRef, OTF2_StringRef,
                   OTF2_LocationGroupType, OTF2_SystemTreeNodeRef>;

using LocalLocationFilter =
    FilterCallback<OTF2_LocationRef, OTF2_LocationRef, OTF2_StringRef,
                   OTF2_LocationType, uint64_t, OTF2_LocationGroupRef>;

using LocalRegionFilter =
    FilterCallback<OTF2_LocationRef, OTF2_RegionRef, OTF2_StringRef,
                   OTF2_StringRef, OTF2_StringRef, OTF2_RegionRole,
                   OTF2_Paradigm, OTF2_RegionFlag, OTF2_StringRef, uint32_t,
                   uint32_t>;

using LocalCallsiteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CallsiteRef, OTF2_StringRef, uint32_t,
                   OTF2_RegionRef, OTF2_RegionRef>;

using LocalCallpathFilter = FilterCallback<OTF2_LocationRef, OTF2_CallpathRef,
                                           OTF2_CallpathRef, OTF2_RegionRef>;

using LocalGroupFilter =
    FilterCallback<OTF2_LocationRef, OTF2_GroupRef, OTF2_StringRef,
                   OTF2_GroupType, OTF2_Paradigm, OTF2_GroupFlag, uint32_t,
                   const uint64_t *>;

using LocalMetricMemberFilter =
    FilterCallback<OTF2_LocationRef, OTF2_MetricMemberRef, OTF2_StringRef,
                   OTF2_StringRef, OTF2_MetricType, OTF2_MetricMode, OTF2_Type,
                   OTF2_Base, int64_t, OTF2_StringRef>;

using LocalMetricClassFilter =
    FilterCallback<OTF2_LocationRef, OTF2_MetricRef, uint8_t,
                   const OTF2_MetricMemberRef *, OTF2_MetricOccurrence,
                   OTF2_RecorderKind>;

using LocalMetricInstanceFilter =
    FilterCallback<OTF2_LocationRef, OTF2_MetricRef, OTF2_MetricRef,
                   OTF2_LocationRef, OTF2_MetricScope, uint64_t>;

using LocalCommFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CommRef, OTF2_StringRef,
                   OTF2_GroupRef, OTF2_CommRef>;

using LocalParameterFilter = FilterCallback<OTF2_LocationRef, OTF2_ParameterRef,
                                            OTF2_StringRef, OTF2_ParameterType>;

using LocalRmaWinFilter = FilterCallback<OTF2_LocationRef, OTF2_RmaWinRef,
                                         OTF2_StringRef, OTF2_CommRef>;

using LocalMetricClassRecorderFilter =
    FilterCallback<OTF2_LocationRef, OTF2_MetricRef, OTF2_LocationRef>;

using LocalSystemTreeNodePropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_SystemTreeNodeRef, OTF2_StringRef,
                   OTF2_Type, OTF2_AttributeValue>;

using LocalSystemTreeNodeDomainFilter =
    FilterCallback<OTF2_LocationRef, OTF2_SystemTreeNodeRef,
                   OTF2_SystemTreeDomain>;

using LocalLocationGroupPropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_LocationGroupRef, OTF2_StringRef,
                   OTF2_Type, OTF2_AttributeValue>;

using LocalLocationPropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_LocationRef, OTF2_StringRef,
                   OTF2_Type, OTF2_AttributeValue>;

using LocalCartDimensionFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CartDimensionRef, OTF2_StringRef,
                   uint32_t, OTF2_CartPeriodicity>;

using LocalCartTopologyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CartTopologyRef, OTF2_StringRef,
                   OTF2_CommRef, uint8_t, const OTF2_CartDimensionRef *>;

using LocalCartCoordinateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CartTopologyRef, uint32_t, uint8_t,
                   const uint32_t *>;

using LocalSourceCodeLocationFilter =
    FilterCallback<OTF2_LocationRef, OTF2_SourceCodeLocationRef, OTF2_StringRef,
                   uint32_t>;

using LocalCallingContextFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CallingContextRef, OTF2_RegionRef,
                   OTF2_SourceCodeLocationRef, OTF2_CallingContextRef>;

using LocalCallingContextPropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CallingContextRef, OTF2_StringRef,
                   OTF2_Type, OTF2_AttributeValue>;

using LocalInterruptGeneratorFilter =
    FilterCallback<OTF2_LocationRef, OTF2_InterruptGeneratorRef, OTF2_StringRef,
                   OTF2_InterruptGeneratorMode, OTF2_Base, int64_t, uint64_t>;

using LocalIoFilePropertyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_IoFileRef, OTF2_StringRef, OTF2_Type,
                   OTF2_AttributeValue>;

using LocalIoRegularFileFilter =
    FilterCallback<OTF2_LocationRef, OTF2_IoFileRef, OTF2_StringRef,
                   OTF2_SystemTreeNodeRef>;

using LocalIoDirectoryFilter =
    FilterCallback<OTF2_LocationRef, OTF2_IoFileRef, OTF2_StringRef,
                   OTF2_SystemTreeNodeRef>;

using LocalIoHandleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_IoHandleRef, OTF2_StringRef,
                   OTF2_IoFileRef, OTF2_IoParadigmRef, OTF2_IoHandleFlag,
                   OTF2_CommRef, OTF2_IoHandleRef>;

using LocalIoPreCreatedHandleStateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_IoHandleRef, OTF2_IoAccessMode,
                   OTF2_IoStatusFlag>;

using LocalCallpathParameterFilter =
    FilterCallback<OTF2_LocationRef, OTF2_CallpathRef, OTF2_ParameterRef,
                   OTF2_Type, OTF2_AttributeValue>;

/*
 *  event filter
 */

using EventBufferFlushFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_TimeStamp>;

using EventMeasurementOnOffFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_MeasurementMode>;

using EventEnterFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp,
                                        OTF2_AttributeList *, OTF2_RegionRef>;

using EventLeaveFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp,
                                        OTF2_AttributeList *, OTF2_RegionRef>;

using EventMpiSendFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, OTF2_CommRef, uint32_t, uint64_t>;

using EventMpiIsendFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, OTF2_CommRef, uint32_t, uint64_t, uint64_t>;

using EventMpiIsendCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventMpiIrecvRequestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventMpiRecvFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, OTF2_CommRef, uint32_t, uint64_t>;

using EventMpiIrecvFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, OTF2_CommRef, uint32_t, uint64_t, uint64_t>;

using EventMpiRequestTestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventMpiRequestCancelledFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventMpiCollectiveBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventMpiCollectiveEndFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CollectiveOp, OTF2_CommRef, uint32_t, uint64_t,
                   uint64_t>;

using EventOmpForkFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp,
                                          OTF2_AttributeList *, uint32_t>;

using EventOmpJoinFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventOmpAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, uint32_t>;

using EventOmpReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint32_t, uint32_t>;

using EventOmpTaskCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventOmpTaskSwitchFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventOmpTaskCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   uint64_t>;

using EventMetricFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_MetricRef, uint8_t, const OTF2_Type *,
                   const OTF2_MetricValue *>;

using EventParameterStringFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_ParameterRef, OTF2_StringRef>;

using EventParameterIntFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_ParameterRef, int64_t>;

using EventParameterUnsignedIntFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_ParameterRef, uint64_t>;

using EventRmaWinCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef>;

using EventRmaWinDestroyFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef>;

using EventRmaCollectiveBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventRmaCollectiveEndFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CollectiveOp, OTF2_RmaSyncLevel, OTF2_RmaWinRef,
                   uint32_t, uint64_t, uint64_t>;

using EventRmaGroupSyncFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaSyncLevel, OTF2_RmaWinRef, OTF2_GroupRef>;

using EventRmaRequestLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t, OTF2_LockType>;

using EventRmaAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t, OTF2_LockType>;

using EventRmaTryLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t, OTF2_LockType>;

using EventRmaReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t>;

using EventRmaSyncFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, OTF2_RmaSyncType>;

using EventRmaWaitChangeFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef>;

using EventRmaPutFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t, uint64_t>;

using EventRmaGetFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, uint64_t, uint64_t>;

using EventRmaAtomicFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint32_t, OTF2_RmaAtomicType, uint64_t,
                   uint64_t, uint64_t>;

using EventRmaOpCompleteBlockingFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint64_t>;

using EventRmaOpCompleteNonBlockingFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint64_t>;

using EventRmaOpTestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint64_t>;

using EventRmaOpCompleteRemoteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_RmaWinRef, uint64_t>;

using EventThreadForkFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_Paradigm, uint32_t>;

using EventThreadJoinFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_Paradigm>;

using EventThreadTeamBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef>;

using EventThreadTeamEndFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef>;

using EventThreadAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_Paradigm, uint32_t, uint32_t>;

using EventThreadReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_Paradigm, uint32_t, uint32_t>;

using EventThreadTaskCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadTaskSwitchFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadTaskCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint64_t>;

using EventThreadBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint64_t>;

using EventThreadWaitFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint64_t>;

using EventThreadEndFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CommRef, uint64_t>;

using EventCallingContextEnterFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CallingContextRef, uint32_t>;

using EventCallingContextLeaveFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CallingContextRef>;

using EventCallingContextSampleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_CallingContextRef, uint32_t,
                   OTF2_InterruptGeneratorRef>;

using EventIoCreateHandleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_IoAccessMode, OTF2_IoCreationFlag,
                   OTF2_IoStatusFlag>;

using EventIoDestroyHandleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef>;

using EventIoDuplicateHandleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_IoHandleRef, OTF2_IoStatusFlag>;

using EventIoSeekFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, int64_t, OTF2_IoSeekOption, uint64_t>;

using EventIoChangeStatusFlagsFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_IoStatusFlag>;

using EventIoDeleteFileFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoParadigmRef, OTF2_IoFileRef>;

using EventIoOperationBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_IoOperationMode, OTF2_IoOperationFlag,
                   uint64_t, uint64_t>;

using EventIoOperationTestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, uint64_t>;

using EventIoOperationIssuedFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, uint64_t>;

using EventIoOperationCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, uint64_t, uint64_t>;

using EventIoOperationCancelledFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, uint64_t>;

using EventIoAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_LockType>;

using EventIoReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_LockType>;

using EventIoTryLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_IoHandleRef, OTF2_LockType>;

using EventProgramBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *,
                   OTF2_StringRef, uint32_t, const OTF2_StringRef *>;

using EventProgramEndFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp,
                                             OTF2_AttributeList *, int64_t>;

template <typename T> class Filter {
  public:
    inline void add(T &f) { m_callbacks.push_back(f); }

    template <typename... ArgTypes> inline bool process(ArgTypes... args) {
        bool b = false;
        for (auto f : m_callbacks) {
            b |= f(args...);
        }
        return b;
    }

  private:
    std::vector<T> m_callbacks;
};
