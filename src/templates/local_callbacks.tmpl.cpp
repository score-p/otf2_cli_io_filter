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
        // auto tr = static_cast<LocalReader *>(userData);
        /*tr->writer().write@@event.name@@Event(location,
                                              time,
                                              attributes@@event.callargs()@@);*/
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
        // auto tr = static_cast<LocalReader *>(userData);
        /*tr->writer().write@@def.name@@Def(location,
                                            attributes@@def.callargs()@@);*/
        return OTF2_CALLBACK_SUCCESS;   
    }
    
    @otf2 endfor
}