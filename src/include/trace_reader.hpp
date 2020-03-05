#ifndef TRACE_READER_H
#define TRACE_READER_H

#include <functional>
#include <memory>
#include <string>

#include "definition_callbacks.hpp"
#include "otf2_writer.hpp"

extern "C" {
#include <otf2/otf2.h>
}

using reader_deleter = std::function<void(OTF2_Reader *)>;
using reader_ptr = std::unique_ptr<OTF2_Reader, reader_deleter>;
using event_reader_deleter = std::function<void(OTF2_GlobalEvtReader *)>;
using event_reader_ptr =
    std::unique_ptr<OTF2_GlobalEvtReader, event_reader_deleter>;

class TraceReader {
  public:
    TraceReader(const std::string &path, Otf2Writer &writer);

    void read();

    inline Otf2Writer &writer() { return m_writer; }

  private:
    void read_definitions();

    Otf2Writer &m_writer;
    reader_ptr m_reader;
    event_reader_ptr m_global_event_reader;
    OTF2_GlobalDefReader *m_global_def_reader;
    std::size_t m_location_count;
    std::vector<OTF2_LocationRef> m_locations;

    friend OTF2_CallbackCode
    definition::LocationCb(void *userData, OTF2_LocationRef location,
                           OTF2_StringRef name, OTF2_LocationType locationType,
                           uint64_t numberOfEvents,
                           OTF2_LocationGroupRef locationGroup);
};

#endif /* TRACE_READER_H */