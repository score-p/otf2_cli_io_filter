#ifndef TRACE_READER_H
#define TRACE_READER_H

#include <bits/c++config.h>
#include <functional>
#include <memory>
#include <string>
#include <thread>

#include <global_callbacks.hpp>
#include <otf2_handler.hpp>

extern "C" {
#include <otf2/otf2.h>
}

using reader_deleter = std::function<void(OTF2_Reader *)>;
using reader_ptr = std::unique_ptr<OTF2_Reader, reader_deleter>;

class TraceReader {
  public:
    TraceReader(const std::string &path, Otf2Handler &writer,
                size_t nthreads = std::thread::hardware_concurrency());

    void read();
    void count() { m_def_count++; }
    inline Otf2Handler &writer() { return m_writer; }

  private:
    std::size_t m_def_count = 0;

    void read_definitions();

    Otf2Handler &m_writer;
    reader_ptr m_reader;
    std::size_t m_location_count;
    std::size_t m_thread_count;
    std::vector<OTF2_LocationRef> m_locations;

    friend OTF2_CallbackCode definition::GlobalLocationCb(
        void *userData, OTF2_LocationRef location, OTF2_StringRef name,
        OTF2_LocationType locationType, uint64_t numberOfEvents,
        OTF2_LocationGroupRef locationGroup);
};

#endif /* TRACE_READER_H */