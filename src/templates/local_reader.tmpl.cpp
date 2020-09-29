#include <local_reader.hpp>
#include <local_callbacks.hpp>

void
LocalReader::read_definitions(OTF2_Reader* reader, const std::vector<size_t> & locations)
{
    bool successful_open_def_files = OTF2_Reader_OpenDefFiles( reader ) == OTF2_SUCCESS;

    OTF2_DefReaderCallbacks* def_callbacks = OTF2_DefReaderCallbacks_New();

    @otf2 for def in defs|local_defs:
    @otf2 if "MappingTable" == def.name or "ClockOffset" == def.name:

    OTF2_DefReaderCallbacks_Set@@def.name@@Callback(def_callbacks, definition::Local@@def.name@@Cb);

    @otf2 endif
    @otf2 endfor

    for (auto location: locations)
    {
        if ( successful_open_def_files )
        {
            OTF2_DefReader* def_reader = OTF2_Reader_GetDefReader( reader, location );

            ReaderLocationPair reader_location{*this, location};
            OTF2_Reader_RegisterDefCallbacks(reader, def_reader, def_callbacks, &reader_location);
            if ( def_reader )
            {
                uint64_t def_reads = 0;
                // FIXME Assume to save state is not good
                // but put all in a pair pointer is also not great
                m_current_location = location;
                OTF2_Reader_ReadAllLocalDefinitions( reader,
                                                    def_reader,
                                                    &def_reads );
                OTF2_Reader_CloseDefReader( reader, def_reader );
            }
        }
        [[maybe_unused]]
        OTF2_EvtReader* evt_reader = OTF2_Reader_GetEvtReader( reader, location );
    }
    if ( successful_open_def_files )
    {
        OTF2_Reader_CloseDefFiles( reader );
    }
}

void
LocalReader::read_events(OTF2_Reader* reader, const std::vector<size_t> & locations)
{
    OTF2_Reader_OpenEvtFiles( reader );

    OTF2_EvtReaderCallbacks* evt_callbacks = OTF2_EvtReaderCallbacks_New();

    @otf2 for event in events:

    OTF2_EvtReaderCallbacks_Set@@event.name@@Callback(evt_callbacks,
                                                      event::Local@@event.name@@Cb);

    @otf2 endfor

    for (auto location: locations)
    {
        OTF2_EvtReader *  evt_reader = OTF2_Reader_GetEvtReader( reader, location);
        OTF2_Reader_RegisterEvtCallbacks(reader,
                                            evt_reader,
                                            evt_callbacks,
                                            this);
        if(evt_reader)
        {
            uint64_t events_read;
            OTF2_Reader_ReadAllLocalEvents(reader,
                                            evt_reader,
                                            &events_read);

            OTF2_Reader_CloseEvtReader(reader,
                                        evt_reader);
        }
    }
    OTF2_EvtReaderCallbacks_Delete( evt_callbacks );
    OTF2_Reader_CloseEvtFiles( reader );
}

void
LocalReader::operator() (OTF2_Reader* reader, std::vector<size_t> locations)
{
    uint64_t number_of_locations_to_read = 0;
    for (auto location: locations)
    {
        number_of_locations_to_read++;
        OTF2_Reader_SelectLocation( reader, location );
    }

    if ( number_of_locations_to_read > 0 )
    {
        read_events(reader, locations);
        read_definitions(reader, locations);
    }
}