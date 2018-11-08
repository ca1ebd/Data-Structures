cmake_minimum_required(VERSION 3.12)
project(apt4)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedCompress LinkedCompress/main.cpp)
add_executable(LinkedCycles LinkedCycles/main.cpp)
add_executable(LinkedExpand LinkedExpand/main.cpp)