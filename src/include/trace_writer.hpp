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

    virtual void
    writeString (OTF2_StringRef self,
		             const char *  	string);

    virtual void
    writeClockProperties(uint64_t              timerResolution,
                         uint64_t              globalOffset,
                         uint64_t              traceLength );

    virtual void
    writeSystemTreeNode(OTF2_SystemTreeNodeRef self,
                        OTF2_StringRef         name,
                        OTF2_StringRef         className,
                        OTF2_SystemTreeNodeRef parent );

    virtual void
    writeLocationGroup(OTF2_LocationGroupRef  self,
                       OTF2_StringRef         name,
                       OTF2_LocationGroupType locationGroupType,
                       OTF2_SystemTreeNodeRef systemTreeParent );

    virtual void
    writeLocation(OTF2_LocationRef      self,
                  OTF2_StringRef        name,
                  OTF2_LocationType     locationType,
                  uint64_t              numberOfEvents,
                  OTF2_LocationGroupRef locationGroup );

    virtual void
    writerEnterEvent(OTF2_LocationRef    location,
                     OTF2_AttributeList * attributeList,
		                 OTF2_TimeStamp  	   time,
		                 OTF2_RegionRef  	   region);

    virtual void
    writerLeaveEvent(OTF2_LocationRef    location,
                     OTF2_AttributeList * attributeList,
		                 OTF2_TimeStamp  	   time,
		                 OTF2_RegionRef  	   region);

  private:
    static OTF2_FlushCallbacks m_flush_callbacks;
    archive_ptr m_archive;
    event_writer_ptr m_event_writer;
    OTF2_GlobalDefWriter* m_def_writer;
};

#endif /* TRACE_WRITER_H */