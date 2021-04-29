cmake_minimum_required(VERSION 3.19)
project(BuilderFacets)

set(CMAKE_CXX_STANDARD 14)

add_executable(BuilderFacets
        Facets.cpp
        Person.cpp
        Person.h
        PersonAddressBuilder.h
        PersonBuilder.cpp
        PersonBuilder.h
        PersonJobBuilder.h)
