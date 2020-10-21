cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

project(otf2_filter_io)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(ClangFormat)
include(Otf2Generate)

option(BUILD_TESTING "" OFF)

find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

find_package(OTF2 REQUIRED)

SET(TEMPLATE_HPP_FILES
"global_callbacks.tmpl.hpp"
"local_callbacks.tmpl.hpp"
"otf2_handler.tmpl.hpp"
"trace_writer.tmpl.hpp"
)

SET(TEMPLATE_CPP_FILES
"global_callbacks.tmpl.cpp"
"local_callbacks.tmpl.cpp"
"trace_writer.tmpl.cpp"
"trace_reader.tmpl.cpp"
"local_reader.tmpl.cpp"
)

generate_otf2_hpp("src/templates"
                  "src/include"
                  "${TEMPLATE_HPP_FILES}")

generate_otf2_cpp("src/templates"
                  "src"
                  "${TEMPLATE_CPP_FILES}")

generate_otf2_hpp("tests/templates"
                  "tests"
                  "itest_handler.tmpl.hpp")

generate_otf2_hpp("src/templates"
                  "src/filter/include"
                  "filter.tmpl.hpp")

generate_otf2_cpp("src/templates"
                  "src/filter"
                  "io_file_filter.tmpl.cpp")

add_subdirectory(src)

if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(tests)
endif()
