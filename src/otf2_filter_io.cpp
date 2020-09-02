#include <trace_reader.hpp>

int main(int argc, char *argv[]) {
    std::string path_out = "./bar";
    TraceWriter tw(path_out);
    TraceReader tr(argv[1], tw, 2);
    tr.read();
    return 0;
}