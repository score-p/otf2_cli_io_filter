#ifndef EVENT_CALLBACKS_HPP
#define EVENT_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace event
{
    @otf2 for event in events:

    OTF2_CallbackCode
    Local@@event.name@@Cb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     uint64_t            eventPosition,
                     void*               userData,
                     OTF2_AttributeList* attributes@@event.funcargs()@@);

    @otf2 endfor
}

namespace definition
{
    @otf2 for def in defs|local_defs:
    @otf2 if "MappingTable" == def.name or "ClockOffset" == def.name:

    OTF2_CallbackCode
    Local@@def.name@@Cb(void* userData @@def.funcargs()@@);

    @otf2 endif
    @otf2 endfor
}
#endif /* EVENT_CALLBACKS_HPP */