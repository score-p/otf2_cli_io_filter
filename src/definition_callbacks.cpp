#include "trace_reader.hpp"

namespace definition
{
    OTF2_CallbackCode
    LocationCb(void*                 userData,
               OTF2_LocationRef      location,
               OTF2_StringRef        name,
               OTF2_LocationType     locationType,
               uint64_t              numberOfEvents,
               OTF2_LocationGroupRef locationGroup)
    {
        auto tr = static_cast<::TraceReader *>(userData);
        if (tr->m_locations.size() == tr->m_location_count)
        {
            return OTF2_CALLBACK_INTERRUPT;
        }
        tr->m_locations.push_back(location);
        tr->writer().writeLocation(location, name, locationType, numberOfEvents, locationGroup);

        return OTF2_CALLBACK_SUCCESS;
    }

    OTF2_CallbackCode
    StringCb(void *userData,
             OTF2_StringRef self,
             const char *string)
    {
        auto tr = static_cast<TraceReader *>(userData);
        tr->writer().writeString(self, string);
        return OTF2_CALLBACK_SUCCESS;
    }

    OTF2_CallbackCode 
    ClockPropertiesCb(void*    userData,
                      uint64_t timerResolution,
                      uint64_t globalOffset,
                      uint64_t traceLength)
    {
        auto tr = static_cast<TraceReader *>(userData);
        tr->writer().writeClockProperties(timerResolution, globalOffset, traceLength);
        return OTF2_CALLBACK_SUCCESS;
    }

    OTF2_CallbackCode 
    SystemTreeNodeCb (void *userData,
                      OTF2_SystemTreeNodeRef self,
                      OTF2_StringRef name,
                      OTF2_StringRef className,
                      OTF2_SystemTreeNodeRef parent)
    {
        auto tr = static_cast<TraceReader *>(userData);
        tr->writer().writeSystemTreeNode(self, name, className, parent);
        return OTF2_CALLBACK_SUCCESS;
    }                   
    OTF2_CallbackCode
    LocationGroupCb (void *userData,
                     OTF2_LocationGroupRef self,
                     OTF2_StringRef name,
                     OTF2_LocationGroupType locationGroupType,
                     OTF2_SystemTreeNodeRef systemTreeParent)
    {
        auto tr = static_cast<TraceReader *>(userData);
        tr->writer().writeLocationGroup(self, name, locationGroupType, systemTreeParent);
        return OTF2_CALLBACK_SUCCESS;
    }
}