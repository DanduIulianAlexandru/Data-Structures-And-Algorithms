cmake_minimum_required(VERSION 3.22)
project(SDA_LAB_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SDA_LAB_3
        App.cpp
        Iterator.cpp
        Iterator.h
        LO.cpp
        LO.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
