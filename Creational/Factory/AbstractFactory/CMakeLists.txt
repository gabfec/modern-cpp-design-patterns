cmake_minimum_required(VERSION 3.10)
project(AbstractFactory)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AbstractFactory
        AbstractFactory.cpp
        CoffeeFactory.h
        DrinkFactory.h
        HotDrink.h
        HotDrinkFactory.h
        TeaFactory.h)
