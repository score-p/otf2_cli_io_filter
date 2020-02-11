#include <trace_filter.hpp>
#include <trace_writer.hpp>
#include <trace_reader.hpp>

int main(int argc, char * argv[])
{
    std::string path_out = "./bar";
    TraceWriter tw(path_out);
    TraceFilter tf(tw);
    TraceReader tr(argv[1], tf);
    tr.read();
    return 0;
}