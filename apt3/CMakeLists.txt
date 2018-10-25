cmake_minimum_required(VERSION 3.12)
project(apt3)

set(CMAKE_CXX_STANDARD 14)

add_executable(apt3 main.cpp)
add_executable(MemberCheck MemberCheck/main.cpp)
add_executable(Encryption Encryption/main.cpp)
add_executable(KittenTree KittenTree/main.cpp)
add_executable(Nesting Nesting/main.cpp)
add_executable(Tourney Tourney/main.cpp)