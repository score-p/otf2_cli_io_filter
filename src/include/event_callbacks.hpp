#ifndef EVENT_CALLBACKS_HPP
#define EVENT_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace event
{
    OTF2_CallbackCode
    EnterCb(OTF2_LocationRef    location,
            OTF2_TimeStamp      time,
            void*               userData,
            OTF2_AttributeList* attributes,
            OTF2_RegionRef      region );

    OTF2_CallbackCode
    LeaveCb(OTF2_LocationRef    location,
            OTF2_TimeStamp      time,
            void*               userData,
            OTF2_AttributeList* attributes,
            OTF2_RegionRef      region );
}

#endif /* EVENT_CALLBACKS_HPP */