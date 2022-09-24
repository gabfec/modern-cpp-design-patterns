cmake_minimum_required(VERSION 3.6)
project(ChatRoom)

set(SOURCE_FILES main.cpp Person.cpp Person.hpp ChatRoom.cpp ChatRoom.hpp)
add_executable(ChatRoom ${SOURCE_FILES})