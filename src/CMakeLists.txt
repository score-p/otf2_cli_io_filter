set(OTF2_FILTER_FMT_SRC
    include/global_callbacks.hpp
    include/local_callbacks.hpp
    include/local_reader.hpp
    include/otf2_handler.hpp
    include/trace_reader.hpp
    include/trace_writer.hpp
    filter/include/filter.hpp
    filter/include/io_file_filter.hpp
    filter/io_file_filter.cpp
    global_callbacks.cpp
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
                              global_callbacks.cpp
                              local_callbacks.cpp
                              filter/io_file_filter.cpp)

target_link_libraries(otf2_filter_io PUBLIC otf2::otf2)

target_include_directories(otf2_filter_io PUBLIC
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/src/filter/include
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(otf2_filter_io PRIVATE -Wall -Werror)