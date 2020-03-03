#include "trace_reader.hpp"

namespace event
{
    @otf2 for event in events:
    
    OTF2_CallbackCode
    @@event.name@@Cb(OTF2_LocationRef    location,
                     OTF2_TimeStamp      time,
                     void*               userData,
                     OTF2_AttributeList* attributes@@event.funcargs()@@)
    {
        auto tr = static_cast<TraceReader *>(userData);
        tr->writer().write@@event.name@@Event(location,
                                              time,
                                              attributes@@event.callargs()@@);
        return OTF2_CALLBACK_SUCCESS;                                               
    }

    @otf2 endfor      
}