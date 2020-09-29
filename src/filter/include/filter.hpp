#pragma once

#include <functional>
#include <iostream>
#include <vector>

extern "C"
{
#include <otf2/otf2.h>
}

template <typename... ArgTypes>
using FilterCallback = std::function<bool(ArgTypes... args)>;

/*
 *  global definition filter
 */

using GlobalClockPropertiesFilter = FilterCallback<uint64_t, uint64_t, uint64_t>;

using GlobalParadigmFilter = FilterCallback<OTF2_Paradigm, OTF2_StringRef, OTF2_ParadigmClass>;

using GlobalParadigmPropertyFilter =
    FilterCallback<OTF2_Paradigm, OTF2_ParadigmProperty, OTF2_Type, OTF2_AttributeValue>;

using GlobalIoParadigmFilter = FilterCallback<OTF2_IoParadigmRef,
                                              OTF2_StringRef,
                                              OTF2_StringRef,
                                              OTF2_IoParadigmClass,
                                              OTF2_IoParadigmFlag,
                                              uint8_t,
                                              const OTF2_IoParadigmProperty *,
                                              const OTF2_Type *,
                                              const OTF2_AttributeValue *>;

using GlobalStringFilter = FilterCallback<OTF2_StringRef, const char *>;

using GlobalAttributeFilter = FilterCallback<OTF2_AttributeRef, OTF2_StringRef, OTF2_StringRef, OTF2_Type>;

using GlobalSystemTreeNodeFilter =
    FilterCallback<OTF2_SystemTreeNodeRef, OTF2_StringRef, OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using GlobalLocationGroupFilter =
    FilterCallback<OTF2_LocationGroupRef, OTF2_StringRef, OTF2_LocationGroupType, OTF2_SystemTreeNodeRef>;

using GlobalLocationFilter =
    FilterCallback<OTF2_LocationRef, OTF2_StringRef, OTF2_LocationType, uint64_t, OTF2_LocationGroupRef>;

using GlobalRegionFilter = FilterCallback<OTF2_RegionRef,
                                          OTF2_StringRef,
                                          OTF2_StringRef,
                                          OTF2_StringRef,
                                          OTF2_RegionRole,
                                          OTF2_Paradigm,
                                          OTF2_RegionFlag,
                                          OTF2_StringRef,
                                          uint32_t,
                                          uint32_t>;

using GlobalCallsiteFilter = FilterCallback<OTF2_CallsiteRef, OTF2_StringRef, uint32_t, OTF2_RegionRef, OTF2_RegionRef>;

using GlobalCallpathFilter = FilterCallback<OTF2_CallpathRef, OTF2_CallpathRef, OTF2_RegionRef>;

using GlobalGroupFilter = FilterCallback<OTF2_GroupRef,
                                         OTF2_StringRef,
                                         OTF2_GroupType,
                                         OTF2_Paradigm,
                                         OTF2_GroupFlag,
                                         uint32_t,
                                         const uint64_t *>;

using GlobalMetricMemberFilter = FilterCallback<OTF2_MetricMemberRef,
                                                OTF2_StringRef,
                                                OTF2_StringRef,
                                                OTF2_MetricType,
                                                OTF2_MetricMode,
                                                OTF2_Type,
                                                OTF2_Base,
                                                int64_t,
                                                OTF2_StringRef>;

using GlobalMetricClassFilter =
    FilterCallback<OTF2_MetricRef, uint8_t, const OTF2_MetricMemberRef *, OTF2_MetricOccurrence, OTF2_RecorderKind>;

using GlobalMetricInstanceFilter =
    FilterCallback<OTF2_MetricRef, OTF2_MetricRef, OTF2_LocationRef, OTF2_MetricScope, uint64_t>;

using GlobalCommFilter = FilterCallback<OTF2_CommRef, OTF2_StringRef, OTF2_GroupRef, OTF2_CommRef>;

using GlobalParameterFilter = FilterCallback<OTF2_ParameterRef, OTF2_StringRef, OTF2_ParameterType>;

using GlobalRmaWinFilter = FilterCallback<OTF2_RmaWinRef, OTF2_StringRef, OTF2_CommRef>;

using GlobalMetricClassRecorderFilter = FilterCallback<OTF2_MetricRef, OTF2_LocationRef>;

using GlobalSystemTreeNodePropertyFilter =
    FilterCallback<OTF2_SystemTreeNodeRef, OTF2_StringRef, OTF2_Type, OTF2_AttributeValue>;

using GlobalSystemTreeNodeDomainFilter = FilterCallback<OTF2_SystemTreeNodeRef, OTF2_SystemTreeDomain>;

using GlobalLocationGroupPropertyFilter =
    FilterCallback<OTF2_LocationGroupRef, OTF2_StringRef, OTF2_Type, OTF2_AttributeValue>;

using GlobalLocationPropertyFilter = FilterCallback<OTF2_LocationRef, OTF2_StringRef, OTF2_Type, OTF2_AttributeValue>;

using GlobalCartDimensionFilter = FilterCallback<OTF2_CartDimensionRef, OTF2_StringRef, uint32_t, OTF2_CartPeriodicity>;

using GlobalCartTopologyFilter =
    FilterCallback<OTF2_CartTopologyRef, OTF2_StringRef, OTF2_CommRef, uint8_t, const OTF2_CartDimensionRef *>;

using GlobalCartCoordinateFilter = FilterCallback<OTF2_CartTopologyRef, uint32_t, uint8_t, const uint32_t *>;

using GlobalSourceCodeLocationFilter = FilterCallback<OTF2_SourceCodeLocationRef, OTF2_StringRef, uint32_t>;

using GlobalCallingContextFilter =
    FilterCallback<OTF2_CallingContextRef, OTF2_RegionRef, OTF2_SourceCodeLocationRef, OTF2_CallingContextRef>;

using GlobalCallingContextPropertyFilter =
    FilterCallback<OTF2_CallingContextRef, OTF2_StringRef, OTF2_Type, OTF2_AttributeValue>;

using GlobalInterruptGeneratorFilter = FilterCallback<OTF2_InterruptGeneratorRef,
                                                      OTF2_StringRef,
                                                      OTF2_InterruptGeneratorMode,
                                                      OTF2_Base,
                                                      int64_t,
                                                      uint64_t>;

using GlobalIoFilePropertyFilter = FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_Type, OTF2_AttributeValue>;

using GlobalIoRegularFileFilter = FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using GlobalIoDirectoryFilter = FilterCallback<OTF2_IoFileRef, OTF2_StringRef, OTF2_SystemTreeNodeRef>;

using GlobalIoHandleFilter = FilterCallback<OTF2_IoHandleRef,
                                            OTF2_StringRef,
                                            OTF2_IoFileRef,
                                            OTF2_IoParadigmRef,
                                            OTF2_IoHandleFlag,
                                            OTF2_CommRef,
                                            OTF2_IoHandleRef>;

using GlobalIoPreCreatedHandleStateFilter = FilterCallback<OTF2_IoHandleRef, OTF2_IoAccessMode, OTF2_IoStatusFlag>;

using GlobalCallpathParameterFilter =
    FilterCallback<OTF2_CallpathRef, OTF2_ParameterRef, OTF2_Type, OTF2_AttributeValue>;

/*
 *  local definition filter
 */

using LocalMappingTableFilter = FilterCallback<OTF2_LocationRef, OTF2_MappingType, const OTF2_IdMap *>;

using LocalClockOffsetFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, int64_t, double>;

/*
 *  event filter
 */

using EventBufferFlushFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_TimeStamp>;

using EventMeasurementOnOffFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_MeasurementMode>;

using EventEnterFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RegionRef>;

using EventLeaveFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RegionRef>;

using EventMpiSendFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint32_t, OTF2_CommRef, uint32_t, uint64_t>;

using EventMpiIsendFilter = FilterCallback<OTF2_LocationRef,
                                           OTF2_TimeStamp,
                                           OTF2_AttributeList *,
                                           uint32_t,
                                           OTF2_CommRef,
                                           uint32_t,
                                           uint64_t,
                                           uint64_t>;

using EventMpiIsendCompleteFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventMpiIrecvRequestFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventMpiRecvFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint32_t, OTF2_CommRef, uint32_t, uint64_t>;

using EventMpiIrecvFilter = FilterCallback<OTF2_LocationRef,
                                           OTF2_TimeStamp,
                                           OTF2_AttributeList *,
                                           uint32_t,
                                           OTF2_CommRef,
                                           uint32_t,
                                           uint64_t,
                                           uint64_t>;

using EventMpiRequestTestFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventMpiRequestCancelledFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventMpiCollectiveBeginFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventMpiCollectiveEndFilter = FilterCallback<OTF2_LocationRef,
                                                   OTF2_TimeStamp,
                                                   OTF2_AttributeList *,
                                                   OTF2_CollectiveOp,
                                                   OTF2_CommRef,
                                                   uint32_t,
                                                   uint64_t,
                                                   uint64_t>;

using EventOmpForkFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint32_t>;

using EventOmpJoinFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventOmpAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint32_t, uint32_t>;

using EventOmpReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint32_t, uint32_t>;

using EventOmpTaskCreateFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventOmpTaskSwitchFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventOmpTaskCompleteFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, uint64_t>;

using EventMetricFilter = FilterCallback<OTF2_LocationRef,
                                         OTF2_TimeStamp,
                                         OTF2_AttributeList *,
                                         OTF2_MetricRef,
                                         uint8_t,
                                         const OTF2_Type *,
                                         const OTF2_MetricValue *>;

using EventParameterStringFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_ParameterRef, OTF2_StringRef>;

using EventParameterIntFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_ParameterRef, int64_t>;

using EventParameterUnsignedIntFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_ParameterRef, uint64_t>;

using EventRmaWinCreateFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef>;

using EventRmaWinDestroyFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef>;

using EventRmaCollectiveBeginFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *>;

using EventRmaCollectiveEndFilter = FilterCallback<OTF2_LocationRef,
                                                   OTF2_TimeStamp,
                                                   OTF2_AttributeList *,
                                                   OTF2_CollectiveOp,
                                                   OTF2_RmaSyncLevel,
                                                   OTF2_RmaWinRef,
                                                   uint32_t,
                                                   uint64_t,
                                                   uint64_t>;

using EventRmaGroupSyncFilter = FilterCallback<OTF2_LocationRef,
                                               OTF2_TimeStamp,
                                               OTF2_AttributeList *,
                                               OTF2_RmaSyncLevel,
                                               OTF2_RmaWinRef,
                                               OTF2_GroupRef>;

using EventRmaRequestLockFilter = FilterCallback<OTF2_LocationRef,
                                                 OTF2_TimeStamp,
                                                 OTF2_AttributeList *,
                                                 OTF2_RmaWinRef,
                                                 uint32_t,
                                                 uint64_t,
                                                 OTF2_LockType>;

using EventRmaAcquireLockFilter = FilterCallback<OTF2_LocationRef,
                                                 OTF2_TimeStamp,
                                                 OTF2_AttributeList *,
                                                 OTF2_RmaWinRef,
                                                 uint32_t,
                                                 uint64_t,
                                                 OTF2_LockType>;

using EventRmaTryLockFilter = FilterCallback<OTF2_LocationRef,
                                             OTF2_TimeStamp,
                                             OTF2_AttributeList *,
                                             OTF2_RmaWinRef,
                                             uint32_t,
                                             uint64_t,
                                             OTF2_LockType>;

using EventRmaReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint32_t, uint64_t>;

using EventRmaSyncFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint32_t, OTF2_RmaSyncType>;

using EventRmaWaitChangeFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef>;

using EventRmaPutFilter = FilterCallback<OTF2_LocationRef,
                                         OTF2_TimeStamp,
                                         OTF2_AttributeList *,
                                         OTF2_RmaWinRef,
                                         uint32_t,
                                         uint64_t,
                                         uint64_t>;

using EventRmaGetFilter = FilterCallback<OTF2_LocationRef,
                                         OTF2_TimeStamp,
                                         OTF2_AttributeList *,
                                         OTF2_RmaWinRef,
                                         uint32_t,
                                         uint64_t,
                                         uint64_t>;

using EventRmaAtomicFilter = FilterCallback<OTF2_LocationRef,
                                            OTF2_TimeStamp,
                                            OTF2_AttributeList *,
                                            OTF2_RmaWinRef,
                                            uint32_t,
                                            OTF2_RmaAtomicType,
                                            uint64_t,
                                            uint64_t,
                                            uint64_t>;

using EventRmaOpCompleteBlockingFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint64_t>;

using EventRmaOpCompleteNonBlockingFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint64_t>;

using EventRmaOpTestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint64_t>;

using EventRmaOpCompleteRemoteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_RmaWinRef, uint64_t>;

using EventThreadForkFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_Paradigm, uint32_t>;

using EventThreadJoinFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_Paradigm>;

using EventThreadTeamBeginFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef>;

using EventThreadTeamEndFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef>;

using EventThreadAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_Paradigm, uint32_t, uint32_t>;

using EventThreadReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_Paradigm, uint32_t, uint32_t>;

using EventThreadTaskCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadTaskSwitchFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadTaskCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint32_t, uint32_t>;

using EventThreadCreateFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint64_t>;

using EventThreadBeginFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint64_t>;

using EventThreadWaitFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint64_t>;

using EventThreadEndFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CommRef, uint64_t>;

using EventCallingContextEnterFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CallingContextRef, uint32_t>;

using EventCallingContextLeaveFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_CallingContextRef>;

using EventCallingContextSampleFilter = FilterCallback<OTF2_LocationRef,
                                                       OTF2_TimeStamp,
                                                       OTF2_AttributeList *,
                                                       OTF2_CallingContextRef,
                                                       uint32_t,
                                                       OTF2_InterruptGeneratorRef>;

using EventIoCreateHandleFilter = FilterCallback<OTF2_LocationRef,
                                                 OTF2_TimeStamp,
                                                 OTF2_AttributeList *,
                                                 OTF2_IoHandleRef,
                                                 OTF2_IoAccessMode,
                                                 OTF2_IoCreationFlag,
                                                 OTF2_IoStatusFlag>;

using EventIoDestroyHandleFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef>;

using EventIoDuplicateHandleFilter = FilterCallback<OTF2_LocationRef,
                                                    OTF2_TimeStamp,
                                                    OTF2_AttributeList *,
                                                    OTF2_IoHandleRef,
                                                    OTF2_IoHandleRef,
                                                    OTF2_IoStatusFlag>;

using EventIoSeekFilter = FilterCallback<OTF2_LocationRef,
                                         OTF2_TimeStamp,
                                         OTF2_AttributeList *,
                                         OTF2_IoHandleRef,
                                         int64_t,
                                         OTF2_IoSeekOption,
                                         uint64_t>;

using EventIoChangeStatusFlagsFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, OTF2_IoStatusFlag>;

using EventIoDeleteFileFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoParadigmRef, OTF2_IoFileRef>;

using EventIoOperationBeginFilter = FilterCallback<OTF2_LocationRef,
                                                   OTF2_TimeStamp,
                                                   OTF2_AttributeList *,
                                                   OTF2_IoHandleRef,
                                                   OTF2_IoOperationMode,
                                                   OTF2_IoOperationFlag,
                                                   uint64_t,
                                                   uint64_t>;

using EventIoOperationTestFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, uint64_t>;

using EventIoOperationIssuedFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, uint64_t>;

using EventIoOperationCompleteFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, uint64_t, uint64_t>;

using EventIoOperationCancelledFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, uint64_t>;

using EventIoAcquireLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, OTF2_LockType>;

using EventIoReleaseLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, OTF2_LockType>;

using EventIoTryLockFilter =
    FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, OTF2_IoHandleRef, OTF2_LockType>;

using EventProgramBeginFilter = FilterCallback<OTF2_LocationRef,
                                               OTF2_TimeStamp,
                                               OTF2_AttributeList *,
                                               OTF2_StringRef,
                                               uint32_t,
                                               const OTF2_StringRef *>;

using EventProgramEndFilter = FilterCallback<OTF2_LocationRef, OTF2_TimeStamp, OTF2_AttributeList *, int64_t>;

class IFilterCallbacks
{
  public:
    struct Callbacks
    {
        /*
         * Global definition callbacks
         */

        GlobalClockPropertiesFilter global_clock_properties_callback;

        GlobalParadigmFilter global_paradigm_callback;

        GlobalParadigmPropertyFilter global_paradigm_property_callback;

        GlobalIoParadigmFilter global_io_paradigm_callback;

        GlobalStringFilter global_string_callback;

        GlobalAttributeFilter global_attribute_callback;

        GlobalSystemTreeNodeFilter global_system_tree_node_callback;

        GlobalLocationGroupFilter global_location_group_callback;

        GlobalLocationFilter global_location_callback;

        GlobalRegionFilter global_region_callback;

        GlobalCallsiteFilter global_callsite_callback;

        GlobalCallpathFilter global_callpath_callback;

        GlobalGroupFilter global_group_callback;

        GlobalMetricMemberFilter global_metric_member_callback;

        GlobalMetricClassFilter global_metric_class_callback;

        GlobalMetricInstanceFilter global_metric_instance_callback;

        GlobalCommFilter global_comm_callback;

        GlobalParameterFilter global_parameter_callback;

        GlobalRmaWinFilter global_rma_win_callback;

        GlobalMetricClassRecorderFilter global_metric_class_recorder_callback;

        GlobalSystemTreeNodePropertyFilter global_system_tree_node_property_callback;

        GlobalSystemTreeNodeDomainFilter global_system_tree_node_domain_callback;

        GlobalLocationGroupPropertyFilter global_location_group_property_callback;

        GlobalLocationPropertyFilter global_location_property_callback;

        GlobalCartDimensionFilter global_cart_dimension_callback;

        GlobalCartTopologyFilter global_cart_topology_callback;

        GlobalCartCoordinateFilter global_cart_coordinate_callback;

        GlobalSourceCodeLocationFilter global_source_code_location_callback;

        GlobalCallingContextFilter global_calling_context_callback;

        GlobalCallingContextPropertyFilter global_calling_context_property_callback;

        GlobalInterruptGeneratorFilter global_interrupt_generator_callback;

        GlobalIoFilePropertyFilter global_io_file_property_callback;

        GlobalIoRegularFileFilter global_io_regular_file_callback;

        GlobalIoDirectoryFilter global_io_directory_callback;

        GlobalIoHandleFilter global_io_handle_callback;

        GlobalIoPreCreatedHandleStateFilter global_io_pre_created_handle_state_callback;

        GlobalCallpathParameterFilter global_callpath_parameter_callback;

        /*
         * Local definition callbacks
         */

        LocalMappingTableFilter local_mapping_table_callback;

        LocalClockOffsetFilter local_clock_offset_callback;

        /*
         * Event filter callbacks
         */

        EventBufferFlushFilter event_buffer_flush_callback;

        EventMeasurementOnOffFilter event_measurement_on_off_callback;

        EventEnterFilter event_enter_callback;

        EventLeaveFilter event_leave_callback;

        EventMpiSendFilter event_mpi_send_callback;

        EventMpiIsendFilter event_mpi_isend_callback;

        EventMpiIsendCompleteFilter event_mpi_isend_complete_callback;

        EventMpiIrecvRequestFilter event_mpi_irecv_request_callback;

        EventMpiRecvFilter event_mpi_recv_callback;

        EventMpiIrecvFilter event_mpi_irecv_callback;

        EventMpiRequestTestFilter event_mpi_request_test_callback;

        EventMpiRequestCancelledFilter event_mpi_request_cancelled_callback;

        EventMpiCollectiveBeginFilter event_mpi_collective_begin_callback;

        EventMpiCollectiveEndFilter event_mpi_collective_end_callback;

        EventOmpForkFilter event_omp_fork_callback;

        EventOmpJoinFilter event_omp_join_callback;

        EventOmpAcquireLockFilter event_omp_acquire_lock_callback;

        EventOmpReleaseLockFilter event_omp_release_lock_callback;

        EventOmpTaskCreateFilter event_omp_task_create_callback;

        EventOmpTaskSwitchFilter event_omp_task_switch_callback;

        EventOmpTaskCompleteFilter event_omp_task_complete_callback;

        EventMetricFilter event_metric_callback;

        EventParameterStringFilter event_parameter_string_callback;

        EventParameterIntFilter event_parameter_int_callback;

        EventParameterUnsignedIntFilter event_parameter_unsigned_int_callback;

        EventRmaWinCreateFilter event_rma_win_create_callback;

        EventRmaWinDestroyFilter event_rma_win_destroy_callback;

        EventRmaCollectiveBeginFilter event_rma_collective_begin_callback;

        EventRmaCollectiveEndFilter event_rma_collective_end_callback;

        EventRmaGroupSyncFilter event_rma_group_sync_callback;

        EventRmaRequestLockFilter event_rma_request_lock_callback;

        EventRmaAcquireLockFilter event_rma_acquire_lock_callback;

        EventRmaTryLockFilter event_rma_try_lock_callback;

        EventRmaReleaseLockFilter event_rma_release_lock_callback;

        EventRmaSyncFilter event_rma_sync_callback;

        EventRmaWaitChangeFilter event_rma_wait_change_callback;

        EventRmaPutFilter event_rma_put_callback;

        EventRmaGetFilter event_rma_get_callback;

        EventRmaAtomicFilter event_rma_atomic_callback;

        EventRmaOpCompleteBlockingFilter event_rma_op_complete_blocking_callback;

        EventRmaOpCompleteNonBlockingFilter event_rma_op_complete_non_blocking_callback;

        EventRmaOpTestFilter event_rma_op_test_callback;

        EventRmaOpCompleteRemoteFilter event_rma_op_complete_remote_callback;

        EventThreadForkFilter event_thread_fork_callback;

        EventThreadJoinFilter event_thread_join_callback;

        EventThreadTeamBeginFilter event_thread_team_begin_callback;

        EventThreadTeamEndFilter event_thread_team_end_callback;

        EventThreadAcquireLockFilter event_thread_acquire_lock_callback;

        EventThreadReleaseLockFilter event_thread_release_lock_callback;

        EventThreadTaskCreateFilter event_thread_task_create_callback;

        EventThreadTaskSwitchFilter event_thread_task_switch_callback;

        EventThreadTaskCompleteFilter event_thread_task_complete_callback;

        EventThreadCreateFilter event_thread_create_callback;

        EventThreadBeginFilter event_thread_begin_callback;

        EventThreadWaitFilter event_thread_wait_callback;

        EventThreadEndFilter event_thread_end_callback;

        EventCallingContextEnterFilter event_calling_context_enter_callback;

        EventCallingContextLeaveFilter event_calling_context_leave_callback;

        EventCallingContextSampleFilter event_calling_context_sample_callback;

        EventIoCreateHandleFilter event_io_create_handle_callback;

        EventIoDestroyHandleFilter event_io_destroy_handle_callback;

        EventIoDuplicateHandleFilter event_io_duplicate_handle_callback;

        EventIoSeekFilter event_io_seek_callback;

        EventIoChangeStatusFlagsFilter event_io_change_status_flags_callback;

        EventIoDeleteFileFilter event_io_delete_file_callback;

        EventIoOperationBeginFilter event_io_operation_begin_callback;

        EventIoOperationTestFilter event_io_operation_test_callback;

        EventIoOperationIssuedFilter event_io_operation_issued_callback;

        EventIoOperationCompleteFilter event_io_operation_complete_callback;

        EventIoOperationCancelledFilter event_io_operation_cancelled_callback;

        EventIoAcquireLockFilter event_io_acquire_lock_callback;

        EventIoReleaseLockFilter event_io_release_lock_callback;

        EventIoTryLockFilter event_io_try_lock_callback;

        EventProgramBeginFilter event_program_begin_callback;

        EventProgramEndFilter event_program_end_callback;
    };
    virtual Callbacks
    get_callbacks() = 0;
};

template <typename T>
class Filter
{
  public:
    inline void
    add(T &f)
    {
        m_callbacks.push_back(f);
    }

    template <typename... ArgTypes>
    inline bool
    process(ArgTypes... args)
    {
        bool b = false;
        for (auto f : m_callbacks)
        {
            b |= f(args...);
        }
        return b;
    }

  private:
    std::vector<T> m_callbacks;
};
