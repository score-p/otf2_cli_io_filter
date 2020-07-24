#ifndef TRACE_WRITER_H
#define TRACE_WRITER_H

#include <cstddef>
#include <memory>
#include <otf2/OTF2_GeneralDefinitions.h>
#include <string>
#include <functional>
#include <unordered_set>

extern "C"
{
    #include <otf2/otf2.h>
}

#include "otf2_handler.hpp"
#include "filter.hpp"

using archive_deleter = std::function<void (OTF2_Archive *)>;
using archive_ptr = std::unique_ptr<OTF2_Archive, archive_deleter>;

using event_writer_deleter = std::function<void (OTF2_EvtWriter *)>;
using event_writer_ptr = std::unique_ptr<OTF2_EvtWriter, event_writer_deleter>;

class TraceWriter: public Otf2Handler {
  public:
    /*
     * Initialize OTF2 archive, event and definition writer.
     *
     * @param path specify the folder of trace to be written
     */
    TraceWriter(const std::string &path);
    virtual ~TraceWriter();

    /*
     * Handle global definitions
     */
    @otf2 for def in defs|global_defs:

    virtual void
    handleGlobal@@def.name@@(@@def.funcargs(leading_comma=False)@@) override;

    @otf2 endfor

    /*
     * Handle local definitions
     */
    @otf2 for def in defs|local_defs:

    virtual void
    handleLocal@@def.name@@(OTF2_LocationRef readLocation,
                            @@def.funcargs(leading_comma=False)@@) override;

    @otf2 endfor

    /*
     * Handle events.
     */
    @otf2 for event in events:

    virtual void
    handle@@event.name@@Event(OTF2_LocationRef    location,
                             OTF2_TimeStamp      time,
                             OTF2_AttributeList* attributes@@event.funcargs()@@) override;

    @otf2 endfor

    void
    register_filter(IFilterCallbacks & filter);

  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    OTF2_GlobalDefWriter* m_def_writer;
    std::unordered_set<OTF2_LocationRef> m_locations;

    @otf2 for def in defs|global_defs:
    Filter<Global@@def.name@@Filter> m_global_@@def.name@@_filter;
    @otf2 endfor

    @otf2 for def in defs|local_defs:
    Filter<Local@@def.name@@Filter> m_local_@@def.name@@_filter;
    @otf2 endfor

    @otf2 for event in events:
    Filter<Event@@event.name@@Filter> m_event_@@event.name@@_filter;
    @otf2 endfor
};

#endif /* TRACE_WRITER_H */