#include <local_callbacks.hpp>
#include <local_reader.hpp>

namespace event
{
    @otf2 for event in events:

    OTF2_CallbackCode
    Local@@event.name@@Cb(OTF2_LocationRef    location,
                          OTF2_TimeStamp      time,
                          uint64_t            eventPosition,
                          void*               userData,
                          OTF2_AttributeList* attributes@@event.funcargs()@@)
    {
        auto tr = static_cast<LocalReader *>(userData);

        tr->handler().handle@@event.name@@Event(location,
                                                time,
                                                attributes@@event.callargs()@@);

        return OTF2_CALLBACK_SUCCESS;
    }

    @otf2 endfor
}

namespace definition
{
    @otf2 for def in defs|local_defs:

    OTF2_CallbackCode
    Local@@def.name@@Cb(void* userData @@def.funcargs()@@)
    {
        auto tr = static_cast<LocalReader *>(userData);
        size_t self_location = tr->current_location();

        tr->handler().handleLocal@@def.name@@(self_location@@def.callargs()@@);
        return OTF2_CALLBACK_SUCCESS;
    }

    @otf2 endfor
}