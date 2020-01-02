add_executable(test_trace_writer test_trace_writer.cpp ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp)

target_link_libraries(test_trace_writer PUBLIC otf2::otf2)

target_include_directories(test_trace_writer PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(test_trace_writer PRIVATE -Wall) 