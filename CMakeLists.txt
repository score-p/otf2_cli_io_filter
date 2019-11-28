cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

project(otf2_filter_io)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(OTF2 REQUIRED)

add_subdirectory(src)