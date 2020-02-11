#include <trace_writer.hpp>
#include <trace_reader.hpp>

#include <iostream>
void test_create(std::string path_in)
{
    std::cout << path_in.c_str() << '\n';
    // TraceReader tr(path_in);
    // tr.read_events();
}

int main(int argc, char * argv[])
{
    test_create(argv[1]);
    return 0;
}