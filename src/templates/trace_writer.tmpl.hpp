#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <memory>
#include <string>
#include <functional>

extern "C"
{
    #include <otf2/otf2.h>
}

#include "otf2_writer.hpp"

using archive_deleter = std::function<void (OTF2_Archive *)>;
using archive_ptr = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void (OTF2_EvtWriter *)>;
using event_writer_ptr = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

class TraceWriter: public Otf2Writer {
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    virtual ~TraceWriter();

    @otf2 for def in defs|global_defs:

    virtual void
    write@@def.name@@(@@def.funcargs(leading_comma=False)@@) override;

    @otf2 endfor
 
  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    event_writer_ptr m_event_writer;
    OTF2_GlobalDefWriter* m_def_writer;
};

#endif /* TRACE_WRITER_H */