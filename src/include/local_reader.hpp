#include <iostream>
#include <vector>

extern "C" {
#include <otf2/otf2.h>
}

class LocalReader {
  public:
    ~LocalReader();

    inline void read_events(OTF2_Reader *reader,
                            const std::vector<size_t> &locations);

    inline void read_definitions(OTF2_Reader *reader,
                                 const std::vector<size_t> &locations);

    void operator()(OTF2_Reader *reader, std::vector<size_t> locations);

    unsigned long int nevents = 0;
    unsigned long int nstring_defs = 0;
};