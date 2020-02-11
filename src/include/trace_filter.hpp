#ifndef TRACE_FILTER_H
#define TRACE_FILTER_H

#include "otf2_writer.hpp"

extern "C"
{
    #include <otf2/otf2.h>
}

class TraceFilter
{
public:
    TraceFilter(Otf2Writer & writer);

private:
    Otf2Writer & m_writer;
};

#endif /* TRACE_FILTER_H */