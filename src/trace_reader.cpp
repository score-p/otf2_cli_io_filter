#include <cassert>
#include <iostream>

#include "trace_reader.hpp"

static OTF2_CallbackCode
Enter_print( OTF2_LocationRef    location,
             OTF2_TimeStamp      time,
             void*               userData,
             OTF2_AttributeList* attributes,
             OTF2_RegionRef      region )
{
    return OTF2_CALLBACK_SUCCESS;
}

static OTF2_CallbackCode
StringCb(void *userData,
         OTF2_StringRef self,
         const char *string);

OTF2_CallbackCode
LocationCb(void*                 userData,
           OTF2_LocationRef      location,
           OTF2_StringRef        name,
           OTF2_LocationType     locationType,
           uint64_t              numberOfEvents,
           OTF2_LocationGroupRef locationGroup);

TraceReader::TraceReader(const std::string &path, TraceFilter & filter)
:m_filter(filter),
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
    
    OTF2_GlobalDefReaderCallbacks_SetLocationCallback(def_callbacks,
                                                      &LocationCb);
    
    OTF2_GlobalDefReaderCallbacks_SetStringCallback(def_callbacks,
                                                    &StringCb);

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
    
    OTF2_GlobalEvtReaderCallbacks_SetEnterCallback(event_callbacks,
                                                   &Enter_print );    

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

OTF2_CallbackCode
LocationCb(void*                 userData,
           OTF2_LocationRef      location,
           OTF2_StringRef        name,
           OTF2_LocationType     locationType,
           uint64_t              numberOfEvents,
           OTF2_LocationGroupRef locationGroup)
{
    auto tr = static_cast<TraceReader *>(userData);
    if (tr->m_locations.size() == tr->m_location_count)
    {
        return OTF2_CALLBACK_INTERRUPT;
    }
    tr->m_locations.push_back(location);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode
StringCb(void *userData,
         OTF2_StringRef self,
         const char *string)
{
    // auto tr = static_cast<TraceReader *>(userData);
    // std::cout << "String " << string << '\n';
    return OTF2_CALLBACK_SUCCESS;
}