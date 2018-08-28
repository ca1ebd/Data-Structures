cmake_minimum_required(VERSION 3.12)
project(apt1)

set(CMAKE_CXX_STANDARD 14)

add_executable(apt1 main.cpp)
add_executable(AccessLevel AccessLevel/main.cpp)
add_executable(Hailstone Hailstone/main.cpp)
add_executable(CommonCount CommonCount/main.cpp)
add_executable(ContinuedFractions ContinuedFractions/main.cpp)
add_executable(CGRatio CGRatio/main.cpp)