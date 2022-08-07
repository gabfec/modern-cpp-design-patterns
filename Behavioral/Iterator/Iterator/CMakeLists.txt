cmake_minimum_required(VERSION 3.16)
project(Iterator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")

add_executable(Iterator
        iterator.cpp generator.h)
