#ifndef TRACE_READER_H
#define TRACE_READER_H
#include <memory>
#include <string>
#include <functional>

extern "C"
{
    #include <otf2/otf2.h>
}

#include "otf2_writer.hpp"

using reader_deleter = std::function<void (OTF2_Reader *)>;
using reader_ptr = std::unique_ptr<OTF2_Reader, reader_deleter>;
using event_reader_deleter = std::function<void (OTF2_GlobalEvtReader *)>;
using event_reader_ptr = std::unique_ptr<OTF2_GlobalEvtReader, event_reader_deleter>;

class TraceReader{
public:
    TraceReader(const std::string &path, const Otf2Writer & writer);

    void read();
private:
    void
    read_definitions();
    void
    read_events();

    const Otf2Writer & m_writer;
    reader_ptr m_reader;
    event_reader_ptr m_global_event_reader;
    OTF2_GlobalDefReader* m_global_def_reader;
    std::size_t m_location_count;
    std::vector<OTF2_LocationRef> m_locations;

    friend OTF2_CallbackCode
    LocationCb(void*                 userData,
           OTF2_LocationRef      location,
           OTF2_StringRef        name,
           OTF2_LocationType     locationType,
           uint64_t              numberOfEvents,
           OTF2_LocationGroupRef locationGroup);
};

#endif /* TRACE_READER_H */