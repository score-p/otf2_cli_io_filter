#include <cassert>
#include <iostream>

#include "trace_reader.hpp"

TraceReader::TraceReader(const std::string &path, Otf2Writer & writer)
:m_writer(writer),
m_reader(OTF2_Reader_Open(path.c_str()), OTF2_Reader_Close),
m_global_event_reader(nullptr,
                      [this](OTF2_GlobalEvtReader *reader){
                          OTF2_Reader_CloseGlobalEvtReader(m_reader.get(), 
                                                           reader);
                      }),
m_location_count(0)
{
    OTF2_Reader_SetSerialCollectiveCallbacks(m_reader.get());
    OTF2_Reader_GetNumberOfLocations(m_reader.get(), &m_location_count);
    m_global_def_reader = OTF2_Reader_GetGlobalDefReader(m_reader.get());
    
    // TODO unique pointer
    OTF2_GlobalDefReaderCallbacks* def_callbacks = OTF2_GlobalDefReaderCallbacks_New();

    @otf2 for def in defs|global_defs:

    OTF2_GlobalDefReaderCallbacks_Set@@def.name@@Callback(def_callbacks, 
                                                          definition::@@def.name@@Cb);

    @otf2 endfor

    OTF2_Reader_RegisterGlobalDefCallbacks(m_reader.get(),
                                           m_global_def_reader,
                                           def_callbacks,
                                           this);
    
    OTF2_GlobalDefReaderCallbacks_Delete(def_callbacks);

    read_definitions();

    m_global_event_reader.reset(OTF2_Reader_GetGlobalEvtReader(m_reader.get()));
    assert(m_global_event_reader != nullptr);

    // TODO unique pointer
    OTF2_GlobalEvtReaderCallbacks* event_callbacks = OTF2_GlobalEvtReaderCallbacks_New();

    OTF2_Reader_RegisterGlobalEvtCallbacks(m_reader.get(),
                                           m_global_event_reader.get(),
                                           event_callbacks,
                                           this);
    
    // OTF2_GlobalEvtReaderCallbacks_SetEnterCallback(event_callbacks,
    //                                                &Enter_print );    

    OTF2_GlobalEvtReaderCallbacks_Delete(event_callbacks);
}

void
TraceReader::read()
{
    uint64_t events_read = 0;
    OTF2_Reader_ReadAllGlobalEvents(m_reader.get(),
                                    m_global_event_reader.get(),
                                    &events_read);
    std::cout << "Read " << events_read << " events\n"; 
}

void
TraceReader::read_definitions()
{
    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions(m_reader.get(),
                                         m_global_def_reader,
                                         &definitions_read);

    for(OTF2_LocationRef location:  m_locations)
    {
        OTF2_Reader_SelectLocation(m_reader.get(), location);
    }

    bool def_files_opened = OTF2_Reader_OpenDefFiles(m_reader.get()) == OTF2_SUCCESS;
    OTF2_Reader_OpenEvtFiles(m_reader.get());

    for (OTF2_LocationRef location:  m_locations)
    {
        if (def_files_opened)
        {
            OTF2_DefReader* def_reader = OTF2_Reader_GetDefReader(m_reader.get(), location);
            if (def_reader)
            {
                uint64_t def_reads = 0;
                OTF2_Reader_ReadAllLocalDefinitions(m_reader.get(),
                                                    def_reader,
                                                    &def_reads);
                OTF2_Reader_CloseDefReader(m_reader.get(), def_reader);
            }
        }
        [[maybe_unused]]
        OTF2_EvtReader* evt_reader = OTF2_Reader_GetEvtReader(m_reader.get(), location);
    }
    
    if (def_files_opened)
    {
        OTF2_Reader_CloseDefFiles(m_reader.get());
    }
}            