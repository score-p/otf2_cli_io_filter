#include <trace_writer.hpp>
#include <trace_reader.hpp>
#include <string>
#include <filesystem>
#include <system_error>
#include <cstring>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "test_handler.hpp"
#include "test_trace.hpp"

namespace fs = std::filesystem;

TEST_CASE( "Test writer API", "[trace_write]" )
{
    auto temp = fs::temp_directory_path();
    temp += fs::path("/temp_trace");
    fs::create_directory(temp);
    REQUIRE(fs::is_directory(temp));
    {
        TraceWriter tw(temp.string());
        std::string trace_input(TestTrace::TestTracePath);
        trace_input += std::string("/") + std::string(TestTrace::TestTraceName) + std::string(".otf2");
        TraceReader tr(trace_input, tw);
        tr.read();
    }
    fs::path trace_output(temp);
    trace_output += fs::path("/trace.otf2");
    REQUIRE( fs::exists(trace_output) );
    {
        TestHandler th;
        TraceReader tr(trace_output, th);
        tr.read();
        th.verify();
    }
    std::error_code ec;
    auto err = fs::remove_all(trace_output.parent_path(), ec);
    REQUIRE(err != static_cast<std::uintmax_t>(-1));
}

class MyRegionFilter
{
public:

    static bool
    filter_string_def(OTF2_StringRef self, const char * string)
    {
        if (strcmp(string, TestTrace::RegionName.data()) == 0)
        {
            m_string_ref = self;
        }
        return false;
    }

    static bool
    filter_region_def(OTF2_RegionRef self, OTF2_StringRef name,
                      OTF2_StringRef canonicalName, OTF2_StringRef description,
                      OTF2_RegionRole regionRole, OTF2_Paradigm paradigm,
                      OTF2_RegionFlag regionFlags, OTF2_StringRef sourceFile,
                      uint32_t beginLineNumber, uint32_t endLineNumber)
    {
        if(name == m_string_ref)
        {
            m_region_ref = self;
        }
        return false;
    }

    static bool
    filter_enter_event(OTF2_LocationRef location,
                                  OTF2_TimeStamp time,
                                  OTF2_AttributeList *attributes,
                                  OTF2_RegionRef region)
    {
        if(region == m_region_ref)
        {
            return true;
        }
        return false;
    }

    static bool
    filter_leave_event(OTF2_LocationRef location,
                       OTF2_TimeStamp time,
                       OTF2_AttributeList *attributes,
                       OTF2_RegionRef region)
    {
        if(region == m_region_ref)
        {
            return true;
        }
        return false;
    }

private:
    static OTF2_StringRef m_string_ref;
    static OTF2_RegionRef m_region_ref;
};

OTF2_StringRef MyRegionFilter::m_string_ref = 0;
OTF2_RegionRef MyRegionFilter::m_region_ref = 0;

TEST_CASE( "Test filter API", "[trace_write_simple_filter]" )
{
    auto temp = fs::temp_directory_path();
    temp += fs::path("/temp_trace");
    fs::create_directory(temp);

    REQUIRE(fs::is_directory(temp));
    {
        TraceWriter tw(temp.string());

        tw.registerStringGlobalFilter(MyRegionFilter::filter_string_def);
        tw.registerRegionGlobalFilter(MyRegionFilter::filter_region_def);
        tw.registerEnterEventFilter(MyRegionFilter::filter_enter_event);
        tw.registerLeaveEventFilter(MyRegionFilter::filter_leave_event);

        std::string trace_input(TestTrace::TestTracePath);
        trace_input += std::string("/") + std::string(TestTrace::TestTraceName) + std::string(".otf2");
        TraceReader tr(trace_input, tw);
        tr.read();
    }

    fs::path trace_output(temp);
    trace_output += fs::path("/trace.otf2");
    TestHandler th;
    TraceReader tr(trace_output, th);
    tr.read();

    CHECK_THROWS(th.invocation_count(std::string(TestTrace::RegionName)));
    REQUIRE(th.locations().count(std::string(TestTrace::LocactionName)) == 1);
    REQUIRE(th.location_groups().count(std::string(TestTrace::LocationGroupName)) == 1);

    std::error_code ec;
    auto err = fs::remove_all(trace_output.parent_path(), ec);
    REQUIRE(err != static_cast<std::uintmax_t>(-1));
}