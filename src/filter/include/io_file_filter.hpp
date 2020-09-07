#pragma once
#include <filesystem>
#include <map>
#include <set>
#include <string>
#include <vector>

extern "C" {
#include <otf2/otf2.h>
}

#include <filter.hpp>

namespace fs = std::filesystem;

class IoFilterPattern {
  public:
    explicit IoFilterPattern(const fs::path &pattern_file);
    bool filterFile(const std::string &file);

  private:
    std::vector<std::string> m_patterns;
};

class IoFileFilter : public IFilterCallbacks {
  public:
    IoFileFilter(const fs::path &pattern_file);
    virtual ~IoFileFilter();
    virtual Callbacks get_callbacks() override;

  private:
    IoFilterPattern m_pattern;
    std::map<OTF2_StringRef, std::string> m_strings;
    std::set<OTF2_IoFileRef> m_io_files;
    std::set<OTF2_IoHandleRef> m_file_handles;

    void add_definition_callbacks(Callbacks &c);
    void add_event_callbacks(Callbacks &c);
};