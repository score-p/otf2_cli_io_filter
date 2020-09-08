#include <cxxopts.hpp>

#include <filesystem>
#include <io_file_filter.hpp>
#include <iostream>
#include <string>
#include <trace_reader.hpp>
#include <trace_writer.hpp>

namespace fs = std::filesystem;

int
main(int argc, char *argv[])
{
    cxxopts::Options options("otf2_filter_io",
                             "This tool filters I/O events "
                             "and definitions out of an "
                             "OTF2 trace file.");

    options.add_options()("i,input", "OTF2 input trace", cxxopts::value<std::string>())(
        "o,output", "OTF2 output trace", cxxopts::value<std::string>())("f,filter",
                                                                        "Filter I/O file filter file "
                                                                        "with shell wildcard pattern",
                                                                        cxxopts::value<std::string>())(
        "t,threads",
        "Number of threads used for "
        "processing",
        cxxopts::value<size_t>()->default_value("2"))("h,help",
                                                      "otf2_filter_io -i "
                                                      "/input/trace.otf2 -o "
                                                      "/output/folder -f filter");

    auto result = options.parse(argc, argv);
    if (result.count("help") || result.count("input") == 0 || result.count("output") == 0 ||
        result.count("filter") == 0)
    {
        std::cout << options.help() << '\n';
        exit(0);
    }

    fs::path input_trace(result["input"].as<std::string>());
    if (!fs::exists(input_trace))
    {
        std::cout << "Input trace does "
                     "not exists\n";
        exit(0);
    }

    fs::path output_trace(result["output"].as<std::string>());
    if (fs::exists(output_trace))
    {
        std::cout << "Output trace "
                     "does exists\n";
        exit(0);
    }

    fs::path filter_file(result["filter"].as<std::string>());
    if (!fs::exists(filter_file))
    {
        std::cout << "Filter file does "
                     "not exists\n";
        exit(0);
    }

    size_t number_of_threads = result["threads"].as<size_t>();

    IoFileFilter filter(filter_file);
    TraceWriter  writer(output_trace);
    writer.register_filter(filter);
    TraceReader reader(input_trace, writer, number_of_threads);
    reader.read();
    return 0;
}