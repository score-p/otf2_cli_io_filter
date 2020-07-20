#ifndef GLOBAL_CALLBACKS_HPP
#define GLOBAL_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace definition
{
    @otf2 for def in defs|global_defs:

    OTF2_CallbackCode
    Global@@def.name@@Cb( void* userData @@def.funcargs()@@ );

    @otf2 endfor
}

#endif /* GLOBAL_CALLBACKS_HPP */