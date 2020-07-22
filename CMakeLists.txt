cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

project(otf2_filter_io)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(ClangFormat)
include(CTest)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

find_package(OTF2 REQUIRED)

macro(generate_otf2 target_name infile outfile)
    add_custom_command(
        OUTPUT ${outfile}
        COMMAND otf2-template ${infile} ${outfile}
    )
    add_custom_target(${target_name} DEPENDS ${outfile})
endmacro()

SET(TEMPLATE_HPP_FILES
    "global_callbacks.tmpl.hpp"
    "local_callbacks.tmpl.hpp"
    "otf2_handler.tmpl.hpp"
    "trace_writer.tmpl.hpp"
    "filter.tmpl.hpp"
)

SET(TEMPLATE_CPP_FILES
    "global_callbacks.tmpl.cpp"
    "local_callbacks.tmpl.cpp"
    "trace_writer.tmpl.cpp"
    "trace_reader.tmpl.cpp"
    "local_reader.tmpl.cpp"
)

SET(TEST_TEMPLATE_HPP_FILES
    "test_handler.tmpl.hpp"
)

add_custom_target(generate)

foreach(infilename ${TEMPLATE_HPP_FILES})
    string(REGEX REPLACE ".tmpl.hpp\$" ".hpp" outfilename ${infilename})
    set(infile_path ${CMAKE_CURRENT_SOURCE_DIR}/src/templates/${infilename})
    set(outfile_path ${CMAKE_CURRENT_SOURCE_DIR}/src/include/${outfilename})

    generate_otf2(${outfilename} ${infile_path} ${outfile_path})
    add_dependencies(generate ${outfilename})
endforeach()

foreach(infilename ${TEMPLATE_CPP_FILES})
    string(REGEX REPLACE ".tmpl.cpp\$" ".cpp" outfilename ${infilename})
    set(infile_path ${CMAKE_CURRENT_SOURCE_DIR}/src/templates/${infilename})
    set(outfile_path ${CMAKE_CURRENT_SOURCE_DIR}/src/${outfilename})

    generate_otf2(${outfilename} ${infile_path} ${outfile_path})
    add_dependencies(generate ${outfilename})
endforeach()

foreach(infilename ${TEST_TEMPLATE_HPP_FILES})
    string(REGEX REPLACE ".tmpl.hpp\$" ".hpp" outfilename ${infilename})
    set(infile_path ${CMAKE_CURRENT_SOURCE_DIR}/tests/templates/${infilename})
    set(outfile_path ${CMAKE_CURRENT_SOURCE_DIR}/tests/${outfilename})

    generate_otf2(${outfilename} ${infile_path} ${outfile_path})
    add_dependencies(generate ${outfilename})
endforeach()

add_subdirectory(src)
add_subdirectory(tests)