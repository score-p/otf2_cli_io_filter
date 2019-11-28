add_executable(otf2_filter_io otf2_filter_io.cpp)

target_link_libraries(otf2_filter_io PUBLIC otf2::otf2)

target_include_directories(otf2_filter_io PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/include)

target_compile_options(otf2_filter_io PRIVATE -Wall -Werror) 
