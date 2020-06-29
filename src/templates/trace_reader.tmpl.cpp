#include <cassert>
#include <iostream>

#include <local_reader.hpp>
#include <trace_reader.hpp>

TraceReader::TraceReader(const std::string &path,
                         Otf2Handler & writer,
                         size_t nthreads)
:m_writer(writer),
m_reader(OTF2_Reader_Open(path.c_str()), OTF2_Reader_Close),
m_location_count(0),
m_thread_count(nthreads)
{
    OTF2_Reader_SetSerialCollectiveCallbacks(m_reader.get());
    OTF2_Reader_GetNumberOfLocations(m_reader.get(), &m_location_count);

    read_definitions();
}
// TODO name it process_events??
void
TraceReader::read()
{
    std::vector<std::thread> workers;

    size_t locations_per_thread = m_locations.size() / m_thread_count;
    size_t rest_locations = m_locations.size() - locations_per_thread * m_thread_count;

    std::vector<size_t> thread_location_count(m_thread_count, locations_per_thread);
    for(int i = 0; rest_locations > 0; rest_locations--, i++)
    {
        thread_location_count[i % m_thread_count]++;
    }

    auto src_begin = m_locations.begin();
    for(size_t i = 0; i < thread_location_count.size(); i++)
    {
        auto thread_locations = std::vector<size_t>(src_begin, src_begin + thread_location_count[i]);
        workers.emplace_back(LocalReader(), m_reader.get(), thread_locations);
        src_begin += thread_location_count[i];
    }
    for(auto & w: workers)
    {
        w.join();
    }
}

void
TraceReader::read_definitions()
{
    OTF2_GlobalDefReader * global_def_reader = OTF2_Reader_GetGlobalDefReader(m_reader.get());

    // TODO unique pointer
    OTF2_GlobalDefReaderCallbacks* def_callbacks = OTF2_GlobalDefReaderCallbacks_New();

    @otf2 for def in defs|global_defs:

    OTF2_GlobalDefReaderCallbacks_Set@@def.name@@Callback(def_callbacks,
                                                          definition::Global@@def.name@@Cb);

    @otf2 endfor

    OTF2_Reader_RegisterGlobalDefCallbacks(m_reader.get(),
                                           global_def_reader,
                                           def_callbacks,
                                           this);

    OTF2_GlobalDefReaderCallbacks_Delete(def_callbacks);

    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions(m_reader.get(),
                                         global_def_reader,
                                         &definitions_read);

    OTF2_Reader_CloseGlobalDefReader(m_reader.get(),
                                     global_def_reader);
}