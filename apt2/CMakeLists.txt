cmake_minimum_required(VERSION 3.12)
project(apt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Anagrams Anagrams/main.cpp CirclesCountry/main.cpp)
add_executable(CarrotBoxes CarrotBoxes/main.cpp)