##############################################################################
# Trace Writer
##############################################################################

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
    ${PROJECT_SOURCE_DIR}/src/filter/include
    ${PROJECT_SOURCE_DIR}/externals/catch2/include)

target_compile_options(test_trace_writer PRIVATE -Wall)

add_test(NAME test_writer
         COMMAND test_trace_writer
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)


set_tests_properties(test_writer PROPERTIES DEPENDS create_test)

##############################################################################
# Trace Reader
##############################################################################

add_executable(test_trace_reader test_trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                                 ${PROJECT_SOURCE_DIR}/src/trace_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_reader.cpp
                                 ${PROJECT_SOURCE_DIR}/src/global_callbacks.cpp
                                 ${PROJECT_SOURCE_DIR}/src/local_callbacks.cpp)

target_link_libraries(test_trace_reader PUBLIC otf2::otf2)

target_include_directories(test_trace_reader PUBLIC
                           ${PROJECT_SOURCE_DIR}/src/include
                           ${PROJECT_SOURCE_DIR}/src/filter/include
                           ${PROJECT_SOURCE_DIR}/externals/catch2/include)

target_compile_options(test_trace_reader PRIVATE -Wall)

add_test(NAME test_reader
         COMMAND test_trace_reader
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

set_tests_properties(test_reader PROPERTIES DEPENDS create_test)

##############################################################################
# I/O File Filter
##############################################################################
add_executable(test_io_filter test_io_filter.cpp
               ${PROJECT_SOURCE_DIR}/src/filter/io_file_filter.cpp)

target_include_directories(test_io_filter PUBLIC
                           ${PROJECT_SOURCE_DIR}/src/filter/include
                           ${PROJECT_SOURCE_DIR}/externals/catch2/include)

add_test(NAME test_io_filter
         COMMAND test_io_filter
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

##############################################################################
# Create MPI Trace File
##############################################################################

find_package(MPI)
if (MPI_CXX_FOUND)

add_executable(create_mpi_trace create_mpi_trace.cpp)

target_link_libraries(create_mpi_trace PUBLIC MPI::MPI_CXX otf2::otf2)

target_include_directories(create_mpi_trace PUBLIC
                           ${PROJECT_SOURCE_DIR}/externals/catch2/include)

set(mpi_run_parameters -np 2 "./create_mpi_trace")

add_test(NAME create_mpi_trace
         COMMAND "mpirun" ${mpi_run_parameters}
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

##############################################################################
# Test Copying MPI Trace File
##############################################################################

add_executable(test_mpi_trace test_mpi_trace.cpp
                              ${PROJECT_SOURCE_DIR}/src/trace_writer.cpp
                              ${PROJECT_SOURCE_DIR}/src/trace_reader.cpp
                              ${PROJECT_SOURCE_DIR}/src/local_reader.cpp
                              ${PROJECT_SOURCE_DIR}/src/global_callbacks.cpp
                              ${PROJECT_SOURCE_DIR}/src/local_callbacks.cpp)

target_link_libraries(test_mpi_trace PUBLIC otf2::otf2)

target_include_directories(test_mpi_trace PUBLIC
                           ${PROJECT_SOURCE_DIR}/src/include
                           ${PROJECT_SOURCE_DIR}/src/filter/include
                           ${PROJECT_SOURCE_DIR}/externals/catch2/include)

add_test(NAME test_mpi_trace
         COMMAND test_mpi_trace
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

set_tests_properties(test_mpi_trace PROPERTIES DEPENDS create_mpi_trace)

endif()
