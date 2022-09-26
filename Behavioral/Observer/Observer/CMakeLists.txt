cmake_minimum_required(VERSION 3.23)
project(Observer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Observer
        main.cpp
        Observable.hpp
        Observer.hpp)
