#include <local_reader.hpp>
#include <local_callbacks.hpp>
#include <definition_callbacks.hpp>

LocalReader::~LocalReader()
{
    if(nevents > 0)
    {
        std::cout << "Read " << nevents << " events.\n";
        std::cout << "Read " << nstring_defs << " string defs.\n";
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
    }
}