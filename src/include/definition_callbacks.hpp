#ifndef DEFINITION_CALLBACKS_HPP
#define DEFINITION_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace definition
{
    OTF2_CallbackCode
    LocationCb(void*                 userData,
            OTF2_LocationRef      location,
            OTF2_StringRef        name,
            OTF2_LocationType     locationType,
            uint64_t              numberOfEvents,
            OTF2_LocationGroupRef locationGroup);

    OTF2_CallbackCode
    StringCb(void *userData,
            OTF2_StringRef self,
            const char *string);

    OTF2_CallbackCode 
    ClockPropertiesCb(void*    userData,
                    uint64_t timerResolution,
                    uint64_t globalOffset,
                    uint64_t traceLength);

    OTF2_CallbackCode 
    SystemTreeNodeCb (void *userData,
                    OTF2_SystemTreeNodeRef self,
                    OTF2_StringRef name,
                    OTF2_StringRef className,
                    OTF2_SystemTreeNodeRef parent);                
    OTF2_CallbackCode
    LocationGroupCb (void *userData,
                    OTF2_LocationGroupRef self,
                    OTF2_StringRef name,
                    OTF2_LocationGroupType locationGroupType,
                    OTF2_SystemTreeNodeRef systemTreeParent);
}

#endif /* DEFINITION_CALLBACKS_HPP */