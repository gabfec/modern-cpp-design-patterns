cmake_minimum_required(VERSION 3.20)
project(BoostFlyweight)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

add_executable(BoostFlyweight
        flyweight.cpp)

target_link_libraries(BoostFlyweight
        Threads::Threads)
