#include <iostream>
#include <otf2/OTF2_GeneralDefinitions.h>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <otf2_handler.hpp>
#include <trace_reader.hpp>

#include "test_trace.hpp"
#include "test_handler.hpp"


class TestHandler : public ITestHandler
{
    using RegionStack = std::deque<OTF2_RegionRef>;

    template<typename Value>
    using LocationMap = std::map<OTF2_LocationRef, Value>;

public:
    virtual void
    handleGlobalString(OTF2_StringRef self,
                       const char *string) override
    {
        m_strings.insert({self, std::string(string)});
    }

    virtual void
    handleGlobalRegion(OTF2_RegionRef self, OTF2_StringRef name,
                       OTF2_StringRef canonicalName, OTF2_StringRef description,
                       OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                       OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
                       uint32_t beginLineNumber, uint32_t endLineNumber) override
    {
        insert_name(name, self, m_regions);
    }

    virtual void
    handleGlobalLocation(OTF2_LocationRef self,
                         OTF2_StringRef name,
                         OTF2_LocationType locationType,
                         uint64_t numberOfEvents,
                         OTF2_LocationGroupRef locationGroup) override
    {
        insert_name(name, m_locations);
    }

    virtual void
    handleGlobalLocationGroup(OTF2_LocationGroupRef self, OTF2_StringRef name,
                              OTF2_LocationGroupType locationGroupType,
                              OTF2_SystemTreeNodeRef systemTreeParent) override
    {
        insert_name(name, m_location_groups);
    }

    virtual void
    handleEnterEvent(OTF2_LocationRef location,
                     OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef region) override
    {
        enter_region(location, region);
    }

    virtual void
    handleLeaveEvent(OTF2_LocationRef location,
                     OTF2_TimeStamp time,
                     OTF2_AttributeList *attributes,
                     OTF2_RegionRef region) override
    {
        leave_region(location, region);
    }

    size_t
    invocation_count(const std::string & region) const
    {
        return m_region_invocations.at(region);
    }

    const std::set<std::string> &
    locations() const
    {
        return m_locations;
    }

    const std::set<std::string> &
    location_groups() const
    {
        return m_location_groups;
    }

private:

    template<typename T, typename Otf2Ref>
    void insert_name(OTF2_StringRef name, Otf2Ref ref, T & container)
    {
        auto search_string = m_strings.find(name);
        if(search_string != m_strings.end())
        {
            container.insert({ref, search_string->second});
        }
    }

    template<typename T>
    void insert_name(OTF2_StringRef name, T & container)
    {
        auto search_string = m_strings.find(name);
        if(search_string != m_strings.end())
        {
            container.insert({search_string->second});
        }
    }

    inline void
    enter_region(OTF2_LocationRef location, OTF2_RegionRef region)
    {
        m_region_stack[location].push_back(region);
    }

    inline void
    leave_region(OTF2_LocationRef location, OTF2_RegionRef left_region)
    {
        auto entered_region = m_region_stack[location].back();
        REQUIRE(entered_region == left_region);
        m_region_stack[location].pop_back();

        auto & region_name = m_regions.at(left_region);

        if(m_region_invocations.find(region_name) != m_region_invocations.end())
        {
            m_region_invocations[region_name]++;
        }
        else
        {
            m_region_invocations.insert({region_name, 1});
        }
    }

    std::map<OTF2_RegionRef, std::string> m_regions;
    LocationMap<RegionStack> m_region_stack;
    std::unordered_map<std::string, size_t> m_region_invocations;

    std::map<OTF2_StringRef, std::string> m_strings;
    std::set<std::string> m_locations;
    std::set<std::string> m_location_groups;
};


TEST_CASE( "Test reader API", "[trace_read]" )
{
    std::string trace_path(TestTrace::TestTracePath);
    trace_path += std::string("/") + std::string(TestTrace::TestTraceName) + std::string(".otf2");
    TestHandler th;
    TraceReader tr(trace_path, th);
    tr.read();
    REQUIRE(th.invocation_count(std::string(TestTrace::RegionName)) == 1);
    REQUIRE(th.locations().count(std::string(TestTrace::LocactionName)) == 1);
    REQUIRE(th.location_groups().count(std::string(TestTrace::LocationGroupName)) == 1);
}
