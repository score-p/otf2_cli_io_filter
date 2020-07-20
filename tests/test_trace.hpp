#pragma once

#include <string_view>

namespace TestTrace{

constexpr std::string_view LocationGroupName = "MasterProcess";
constexpr std::string_view LocactionName = "MainThread";
constexpr std::string_view RegionName = "MyFunction";
constexpr std::string_view TestTracePath = "tests/TestTracePath";
constexpr std::string_view TestTraceName = "TestTrace";

};