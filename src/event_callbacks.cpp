#include "trace_reader.hpp"

namespace event
{
    OTF2_CallbackCode
    EnterCb(OTF2_LocationRef    location,
            OTF2_TimeStamp      time,
            void*               userData,
            OTF2_AttributeList* attributes,
            OTF2_RegionRef      region )
    {
        auto tr = static_cast<TraceReader *>(userData);
        
        tr->writer().writerEnterEvent(location,
                                      attributes,
                                      time,
                                      region);
        
        return OTF2_CALLBACK_SUCCESS;
    }            

    OTF2_CallbackCode
    LeaveCb(OTF2_LocationRef    location,
            OTF2_TimeStamp      time,
            void*               userData,
            OTF2_AttributeList* attributes,
            OTF2_RegionRef      region )
    {
        auto tr = static_cast<TraceReader *>(userData);
        
        tr->writer().writerLeaveEvent(location,
                                      attributes,
                                      time,
                                      region);
        
        return OTF2_CALLBACK_SUCCESS;
    }            
}