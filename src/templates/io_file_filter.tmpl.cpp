#include <algorithm>
#include <fstream>
#include <stdexcept>

#include <io_file_filter.hpp>

extern "C" {
#include <fnmatch.h>
}

IoFilterPattern::IoFilterPattern(const fs::path & pattern_file)
{
    std::ifstream in(pattern_file, std::ios::in);
    if(! in.is_open())
    {
        throw std::runtime_error("Could not load pattern file: " + pattern_file.string());
    }
    std::string line;
    while(std::getline(in, line))
    {
        m_patterns.push_back(line);
    }
}

bool
IoFilterPattern::filterFile(const std::string &file)
{
    return std::any_of(m_patterns.begin(),
                       m_patterns.end(),
                       [&file](const std::string & p) -> bool
                       {
                           return fnmatch(p.c_str(), file.c_str(), FNM_PATHNAME | FNM_LEADING_DIR) == 0;
                       });
}

IoFileFilter::IoFileFilter(const fs::path & pattern_file)
:m_pattern(pattern_file)
{}

IoFileFilter::~IoFileFilter()
{}

IFilterCallbacks::Callbacks
IoFileFilter::get_callbacks()
{
    Callbacks c;

    add_definition_callbacks(c);
    add_event_callbacks(c);

    return c;
}

void IoFileFilter::add_definition_callbacks(Callbacks & c)
{
    c.global_string_callback = [this](OTF2_StringRef self,
                                     const char *    string){
        m_strings.insert({self, string});
        return false;
    };

    c.global_io_regular_file_callback = [this] (OTF2_IoFileRef self,
                                                OTF2_StringRef name,
                                                OTF2_SystemTreeNodeRef scope){
        auto search = m_strings.find(name);
        if (search != m_strings.end() && m_pattern.filterFile(search->second)) {
            m_io_files.insert(self);
            return true;
        }
        return false;
    };

    c.global_io_file_property_callback = [this] (OTF2_IoFileRef ioFile,
                                                 OTF2_StringRef name,
                                                 OTF2_Type type,
                                                 OTF2_AttributeValue value){
        return m_io_files.find(ioFile) != m_io_files.end();
    };

    c.global_io_handle_callback = [this] (OTF2_IoHandleRef self,
                                          OTF2_StringRef name,
                                          OTF2_IoFileRef file,
                                          OTF2_IoParadigmRef ioParadigm,
                                          OTF2_IoHandleFlag ioHandleFlags,
                                          OTF2_CommRef comm,
                                          OTF2_IoHandleRef parent){

        auto search_file = m_io_files.find(file);
        if(search_file != m_io_files.end())
        {
            m_file_handles.insert(self);
            return true;
        }

        auto search_handle = m_file_handles.find(parent);
        if(search_handle != m_file_handles.end())
        {
            return true;
        }
        return false;
    };
}

void IoFileFilter::add_event_callbacks(Callbacks & c)
{
    @otf2 for evt in events:
    @otf2  if evt.lower.startswith("io_") and not evt.lower.startswith("io_duplicate") and not evt.lower.startswith("io_delete_file"):
    c.event_@@evt.lower@@_callback = [this](OTF2_LocationRef    location,
                                            OTF2_TimeStamp      time,
                                            OTF2_AttributeList* attributes@@evt.funcargs()@@)
    {
        return m_file_handles.find(handle) != m_file_handles.end();
    };
    @otf2 endif
    @otf2 endfor

    c.event_io_duplicate_handle_callback = [this](OTF2_LocationRef location,
                                                  OTF2_TimeStamp time,
                                                  OTF2_AttributeList *attributes,
                                                  OTF2_IoHandleRef oldHandle,
                                                  OTF2_IoHandleRef newHandle,
                                                  OTF2_IoStatusFlag statusFlags)
    {
        bool filter = m_file_handles.find(oldHandle) != m_file_handles.end()
                      && m_file_handles.find(newHandle) != m_file_handles.end();
        return filter;
    };

    c.event_io_delete_file_callback = [this](OTF2_LocationRef location,
                                             OTF2_TimeStamp time,
                                             OTF2_AttributeList *attributes,
                                             OTF2_IoParadigmRef ioParadigm,
                                             OTF2_IoFileRef file)
    {
        return m_io_files.find(file) != m_io_files.end();
    };
}