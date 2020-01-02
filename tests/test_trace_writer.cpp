#include <trace_writer.hpp>
void test_create()
{
    std::string path = "./foo";
    TraceWriter tw(path);
}

int main()
{
    test_create();
    return 0;
}