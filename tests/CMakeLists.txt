add_executable(test_trace_writer test_trace_writer.cpp 
                                 ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/definition_callbacks.cpp
                                 ${PROJECT_SOURCE_DIR}/src/event_callbacks.cpp)

target_link_libraries(test_trace_writer PUBLIC otf2::otf2)

target_include_directories(test_trace_writer PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(test_trace_writer PRIVATE -Wall) 

add_executable(test_trace_reader test_trace_reader.cpp 
                                 ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/definition_callbacks.cpp
                                 ${PROJECT_SOURCE_DIR}/src/event_callbacks.cpp)

target_link_libraries(test_trace_reader PUBLIC otf2::otf2)

target_include_directories(test_trace_reader PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(test_trace_reader PRIVATE -Wall) 