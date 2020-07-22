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


TEST_CASE( "Test reader API", "[trace_read]" )
{
    std::string trace_path(TestTrace::TestTracePath);
    trace_path += std::string("/") + std::string(TestTrace::TestTraceName) + std::string(".otf2");
    TestHandler th;
    TraceReader tr(trace_path, th);
    tr.read();
    th.verify();
}
