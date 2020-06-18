#ifndef OTF2_WRITER_H
#define OTF2_WRITER_H

extern "C"
{
    #include <otf2/otf2.h>
}

class Otf2Writer{
public:

    @otf2 for def in defs|global_defs:

    virtual void
    write@@def.name@@(@@def.funcargs(leading_comma=False)@@) = 0;

    @otf2 endfor

    @otf2 for event in events:

    virtual void
    write@@event.name@@Event(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList* attributes@@event.funcargs()@@) = 0;
    
    @otf2 endfor
};

#endif /* OTF2_WRITER_H */