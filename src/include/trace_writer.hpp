#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <memory>
#include <string>
#include <functional>

#include <otf2/otf2.h>

using archive_deleter = std::function<void (OTF2_Archive *)>;
using archive_ptr = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void (OTF2_EvtWriter *)>;
using event_writer_ptr = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

using def_writer_deleter = std::function<void (OTF2_GlobalDefWriter *)>;
using def_writer_ptr = std::unique_ptr<OTF2_GlobalDefWriter, def_writer_deleter>;

class TraceWriter {
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    ~TraceWriter();

  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    event_writer_ptr m_event_writer;
    def_writer_ptr m_def_writer;
};

#endif /* TRACE_WRITER_H */