#ifndef OTF2_HANDLER_H
#define OTF2_HANDLER_H

extern "C"
{
    #include <otf2/otf2.h>
}

class Otf2Handler{
public:

    /*
     * Handle global definitions
     */
    @otf2 for def in defs|global_defs:

    virtual void
    handleGlobal@@def.name@@(@@def.funcargs(leading_comma=False)@@) = 0;

    @otf2 endfor

    /*
     * Handle local definitions
     */
    @otf2 for def in defs|local_defs:

    virtual void
    handleLocal@@def.name@@(OTF2_LocationRef readLocation,
                            @@def.funcargs(leading_comma=False)@@) = 0;

    @otf2 endfor

    /*
     * Handle events.
     */
    @otf2 for event in events:

    virtual void
    handle@@event.name@@Event(OTF2_LocationRef    location,
                              OTF2_TimeStamp      time,
                              OTF2_AttributeList* attributes@@event.funcargs()@@) = 0;

    @otf2 endfor
};

#endif /* OTF2_HANDLER_H */