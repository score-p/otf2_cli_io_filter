#include <iostream>
#include <utility>
#include <vector>

#include <otf2_handler.hpp>

extern "C"
{
#include <otf2/otf2.h>
}

class LocalReader;

using ReaderLocationPair = std::pair<LocalReader &, size_t>;

class LocalReader
{
  public:
    LocalReader(Otf2Handler &handler) : m_handler(handler)
    {
    }

    void
    operator()(OTF2_Reader *reader, std::vector<size_t> locations);

    size_t
    current_location()
    {
        return m_current_location;
    }

    Otf2Handler &
    handler()
    {
        return m_handler;
    }

  private:
    inline void
    read_events(OTF2_Reader *reader, const std::vector<size_t> &locations);

    inline void
    read_definitions(OTF2_Reader *reader, const std::vector<size_t> &locations);

    Otf2Handler &m_handler;
    size_t       m_current_location;
};