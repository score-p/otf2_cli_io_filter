set(OTF2_FILTER_FMT_SRC 
    include/global_callbacks.hpp
    include/filtered_writer.hpp
    include/local_callbacks.hpp
    include/local_reader.hpp
    include/otf2_writer.hpp
    include/trace_reader.hpp
    include/trace_writer.hpp
    global_callbacks.cpp
    filtered_writer.cpp
    local_callbacks.cpp
    local_reader.cpp
    trace_reader.cpp
    trace_writer.cpp
    otf2_filter_io.cpp)

clangformat_setup(${OTF2_FILTER_FMT_SRC})

add_executable(otf2_filter_io otf2_filter_io.cpp 
                              trace_writer.cpp
                              trace_reader.cpp
                              local_reader.cpp
                              filtered_writer.cpp
                              global_callbacks.cpp
                              local_callbacks.cpp)
                              
target_link_libraries(otf2_filter_io PUBLIC otf2::otf2)

target_include_directories(otf2_filter_io PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(otf2_filter_io PRIVATE -Wall -Werror) 
