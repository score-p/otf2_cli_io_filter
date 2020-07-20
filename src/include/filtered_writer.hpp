#ifndef TRACE_FILTER_H
#define TRACE_FILTER_H

#include "trace_writer.hpp"

class FilteredWriter : public TraceWriter {
  public:
    FilteredWriter(const std::string &path);
};

#endif /* TRACE_FILTER_H */