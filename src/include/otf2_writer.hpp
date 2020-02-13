#ifndef OTF2_WRITER_H
#define OTF2_WRITER_H

#include <otf2/otf2.h>

class Otf2Writer{
public:
    virtual void
    writeString (OTF2_StringRef self,
		         const char *  	string) = 0;
    
    virtual void
    writeClockProperties(uint64_t              timerResolution,
                         uint64_t              globalOffset,
                         uint64_t              traceLength ) = 0;

    virtual void
    writeSystemTreeNode(OTF2_SystemTreeNodeRef self,
                        OTF2_StringRef         name,
                        OTF2_StringRef         className,
                        OTF2_SystemTreeNodeRef parent ) = 0;

    virtual void
    writeLocationGroup(OTF2_LocationGroupRef  self,
                       OTF2_StringRef         name,
                       OTF2_LocationGroupType locationGroupType,
                       OTF2_SystemTreeNodeRef systemTreeParent ) = 0;

    virtual void
    writeLocation(OTF2_LocationRef      self,
                  OTF2_StringRef        name,
                  OTF2_LocationType     locationType,
                  uint64_t              numberOfEvents,
                  OTF2_LocationGroupRef locationGroup ) = 0;

    virtual void
    writerEnterEvent(OTF2_LocationRef    location,
                     OTF2_AttributeList * attributeList,
		             OTF2_TimeStamp  	   time,
		             OTF2_RegionRef  	   region) = 0;

    virtual void
    writerLeaveEvent(OTF2_LocationRef    location,
                     OTF2_AttributeList * attributeList,
		             OTF2_TimeStamp  	   time,
		             OTF2_RegionRef  	   region) = 0;
};

#endif /* OTF2_WRITER_H */