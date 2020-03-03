#include <cassert>
#include <trace_writer.hpp>

OTF2_FlushType pre_flush(void *userData, OTF2_FileType fileType,
                         OTF2_LocationRef location, void *callerData,
                         bool final) {
    return OTF2_FLUSH;
}

OTF2_FlushCallbacks TraceWriter::m_flush_callbacks = {
    .otf2_pre_flush = pre_flush, .otf2_post_flush = nullptr};

void delete_event_writer(OTF2_EvtWriter *writer, OTF2_Archive *archive) {
    if (nullptr != archive && nullptr != writer) {
        OTF2_Archive_CloseEvtWriter(archive, writer);
    }
}

void delete_archive(OTF2_Archive *archive) {
    if (nullptr != archive) {
        OTF2_Archive_Close(archive);
    }
}

TraceWriter::TraceWriter(const std::string &path)
    : m_archive(nullptr, delete_archive)
{
    auto *archive =
        OTF2_Archive_Open(path.c_str(), "trace", OTF2_FILEMODE_WRITE,
                          1024 * 1024 /* event chunk size */,
                          4 * 1024 * 1024 /* def chunk size */,
                          OTF2_SUBSTRATE_POSIX, OTF2_COMPRESSION_NONE);

    OTF2_Archive_SetFlushCallbacks(archive, &m_flush_callbacks, nullptr);
    OTF2_Archive_SetSerialCollectiveCallbacks(archive);
    m_archive.reset(archive);

    OTF2_Archive_OpenEvtFiles(archive);

    m_def_writer = OTF2_Archive_GetGlobalDefWriter(archive);
    assert(m_def_writer);
}

TraceWriter::~TraceWriter() {
    OTF2_Archive_CloseDefFiles(m_archive.get());
    for(const auto & [location, dummy]: m_event_writer)
    {
        OTF2_DefWriter* def_writer = OTF2_Archive_GetDefWriter( m_archive.get(),
                                                                location );
        OTF2_Archive_CloseDefWriter( m_archive.get(), def_writer );
    }
    OTF2_Archive_CloseEvtFiles(m_archive.get());
}

@otf2 for def in defs|global_defs:

void
TraceWriter::write@@def.name@@(@@def.funcargs(leading_comma=False)@@)
{
    OTF2_GlobalDefWriter_Write@@def.name@@(m_def_writer@@def.callargs()@@);
    @otf2  if def.name == 'Location':
    auto search = m_event_writer.find(self);
    if(search == m_event_writer.end())
    {
        m_event_writer.emplace(self, event_writer_ptr(OTF2_Archive_GetEvtWriter(m_archive.get(), self),
                                                        [this](OTF2_EvtWriter *writer) {
                                                            delete_event_writer(writer, m_archive.get());
                                                        }));
    }
    @otf2 endif
}

@otf2 endfor

@otf2 for event in events:

void
TraceWriter::write@@event.name@@Event(OTF2_LocationRef    location,
                                      OTF2_TimeStamp      time,
                                      OTF2_AttributeList* attributes@@event.funcargs()@@)
{
    OTF2_EvtWriter_@@event.name@@(m_event_writer[location].get(),
                                  attributes,
                                  time@@event.callargs()@@);                                  
}

@otf2 endfor
