#ifndef DEFINITION_CALLBACKS_HPP
#define DEFINITION_CALLBACKS_HPP

extern "C"
{
    #include <otf2/otf2.h>
}

namespace definition
{
    @otf2 for def in defs|global_defs:

    OTF2_CallbackCode
    @@def.name@@Cb( void* userData @@def.funcargs()@@ );

    @otf2 endfor
}

#endif /* DEFINITION_CALLBACKS_HPP */