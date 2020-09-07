#include <fstream>
#include <filesystem>
#include <ios>
#include <string>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <io_file_filter.hpp>

namespace fs = std::filesystem;

void create_pattern_file(const std::string & pattern_file_path)
{
    fs::path pattern_file(pattern_file_path);
    std::ofstream out(pattern_file, std::ios::out);
    REQUIRE(out.is_open());

    out << "/proc/*\n";
    out << "/home/bar/foo.txt\n";
}

TEST_CASE("Test IoFilterPattern", "[init]")
{
    auto temp = fs::temp_directory_path();
    temp += "/io_filter_pattern.txt";
    create_pattern_file(temp);

    IoFilterPattern ifp(temp);

    const std::string foo_file = "/home/bar/foo.txt";
    REQUIRE(ifp.filterFile(foo_file));

    const std::string wrong_foo_file = "/home/bar/foo";
    REQUIRE(! ifp.filterFile(wrong_foo_file));

    const std::string proc_file = "/proc/self/1000";
    REQUIRE(ifp.filterFile(proc_file));
}