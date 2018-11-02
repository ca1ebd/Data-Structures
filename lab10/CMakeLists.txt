cmake_minimum_required(VERSION 3.10)
project(rwg)

set(CMAKE_CXX_STANDARD 11)

include_directories(../../adit/Downloads/lab10/lab10)

add_executable(rwg main.cpp Queue.h)
