add_executable(create_test_trace create_test_trace.cpp)

target_link_libraries(create_test_trace PUBLIC otf2::otf2)

target_compile_options(create_test_trace PRIVATE -Wall)

add_test(NAME create_test
         COMMAND create_test_trace
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

add_executable(test_trace_writer test_trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/global_callbacks.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_callbacks.cpp)

target_link_libraries(test_trace_writer PUBLIC otf2::otf2)

target_include_directories(test_trace_writer PUBLIC
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/externals/catch2/include)

target_compile_options(test_trace_writer PRIVATE -Wall)

add_test(NAME test_writer
         COMMAND test_trace_writer
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)


set_tests_properties(test_writer PROPERTIES DEPENDS create_test)

add_executable(test_trace_reader test_trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/global_callbacks.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_callbacks.cpp)

target_link_libraries(test_trace_reader PUBLIC otf2::otf2)

target_include_directories(test_trace_reader PUBLIC
                           ${PROJECT_SOURCE_DIR}/src/include
                           ${PROJECT_SOURCE_DIR}/externals/catch2/include)

target_compile_options(test_trace_reader PRIVATE -Wall)

add_test(NAME test_reader
         COMMAND test_trace_reader
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)


set_tests_properties(test_reader PROPERTIES DEPENDS create_test)
