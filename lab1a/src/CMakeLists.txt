cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab1
        Message.cpp
        MessageLog.h
        main.cpp
        MessageLog.cpp
        modes.cpp
        modes.h test/doctest.h test/doctest_main.cpp test/tests.cpp)
