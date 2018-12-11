cmake_minimum_required(VERSION 3.12)
project(EC)

set(CMAKE_CXX_STANDARD 14)

add_executable(SubWord SubWord/main.cpp)
add_executable(Metaprogramming Metaprogramming/main.cpp)
add_executable(IsomorphicWords IsomorphicWords/main.cpp)
add_executable(RatRoute RatRoute/main.cpp)