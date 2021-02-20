cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab1
        functions.cpp
        functions.h
        main.cpp
        message.cpp
        message.h
        modes.cpp
        modes.h test/doctest.h test/doctest_main.cpp test/tests.cpp)
