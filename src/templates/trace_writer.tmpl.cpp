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
    for(auto location: m_locations)
    {
        OTF2_DefWriter* def_writer = OTF2_Archive_GetDefWriter( m_archive.get(),
                                                                location );
        OTF2_Archive_CloseDefWriter( m_archive.get(), def_writer );
    }
    OTF2_Archive_CloseEvtFiles(m_archive.get());
}

@otf2 for def in defs|global_defs:

void
TraceWriter::handleGlobal@@def.name@@(@@def.funcargs(leading_comma=False)@@)
{
    @otf2  if def.name == 'Location':
    m_locations.insert(self);
    @otf2 endif

    bool filter_out = m_global_@@def.name@@_filter.process(@@def.callargs(leading_comma=False)@@);
    if(! filter_out)
    {
        OTF2_GlobalDefWriter_Write@@def.name@@(m_def_writer@@def.callargs()@@);
    }
}

@otf2 endfor

@otf2 for def in defs|local_defs:

void
TraceWriter::handleLocal@@def.name@@(OTF2_LocationRef readLocation,
                                     @@def.funcargs(leading_comma=False)@@)
{
    bool filter_out = m_local_@@def.name@@_filter.process(readLocation@@def.callargs()@@);
    if(! filter_out)
    {
        auto * local_def_writer = OTF2_Archive_GetDefWriter(m_archive.get(), readLocation);
        OTF2_DefWriter_Write@@def.name@@(local_def_writer@@def.callargs()@@);
    }
}

@otf2 endfor

@otf2 for event in events:

void
TraceWriter::handle@@event.name@@Event(OTF2_LocationRef    location,
                                       OTF2_TimeStamp      time,
                                       OTF2_AttributeList* attributes@@event.funcargs()@@)
{
    bool filter_out = m_event_@@event.name@@_filter.process(location, time, attributes@@event.callargs()@@);
    if(! filter_out)
    {
        auto * event_writer = OTF2_Archive_GetEvtWriter(m_archive.get(), location);
        OTF2_EvtWriter_@@event.name@@(event_writer,
                                    attributes,
                                    time@@event.callargs()@@);
    }
}

@otf2 endfor

@otf2 for def in defs|global_defs:

void
TraceWriter::register@@def.name@@GlobalFilter(Global@@def.name@@Filter filter)
{
    m_global_@@def.name@@_filter.add(filter);
}

@otf2 endfor

@otf2 for def in defs|local_defs:

void
TraceWriter::register@@def.name@@LocalFilter(Local@@def.name@@Filter filter)
{
    m_local_@@def.name@@_filter.add(filter);
}

@otf2 endfor

@otf2 for event in events:

void
TraceWriter::register@@event.name@@EventFilter(Event@@event.name@@Filter filter)
{
    m_event_@@event.name@@_filter.add(filter);
}

@otf2 endfor