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
    @@event.name@@Cb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     void*               userData,
                     OTF2_AttributeList* attributes@@event.funcargs()@@);

    @otf2 endfor
}

#endif /* EVENT_CALLBACKS_HPP */