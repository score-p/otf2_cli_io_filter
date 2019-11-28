#include <iostream>
#include <cinttypes>

#include <otf2/otf2.h>

static OTF2_CallbackCode
GlobDefLocation_Register( void*                 userData,
                          OTF2_LocationRef      location,
                          OTF2_StringRef        name,
                          OTF2_LocationType     locationType,
                          uint64_t              numberOfEvents,
                          OTF2_LocationGroupRef locationGroup )
{
    return OTF2_CALLBACK_SUCCESS;
}

int main(int argc, char * argv[])
{
    OTF2_Reader* reader = OTF2_Reader_Open(argv[1]);
    OTF2_Reader_SetSerialCollectiveCallbacks(reader);

    uint64_t number_of_locations;
    OTF2_Reader_GetNumberOfLocations(reader, &number_of_locations);

    OTF2_GlobalDefReader* global_def_reader = OTF2_Reader_GetGlobalDefReader( reader );

    OTF2_GlobalDefReaderCallbacks* global_def_callbacks = OTF2_GlobalDefReaderCallbacks_New();
    
    OTF2_GlobalDefReaderCallbacks_SetLocationCallback( global_def_callbacks,
                                                       &GlobDefLocation_Register );
    OTF2_Reader_RegisterGlobalDefCallbacks( reader,
                                            global_def_reader,
                                            global_def_callbacks,
                                            nullptr );

    OTF2_GlobalDefReaderCallbacks_Delete( global_def_callbacks );

    uint64_t definitions_read = 0;
    OTF2_Reader_ReadAllGlobalDefinitions( reader,
                                          global_def_reader,
                                          &definitions_read );

    OTF2_Reader_Close( reader );

    return 0;
}