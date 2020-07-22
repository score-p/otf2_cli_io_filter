#include <trace_writer.hpp>
#include <trace_reader.hpp>
#include <string>
#include <filesystem>
#include <system_error>


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