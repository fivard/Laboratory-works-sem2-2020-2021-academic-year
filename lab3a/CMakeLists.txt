cmake_minimum_required(VERSION 3.17)
project(lab3a)

set(CMAKE_CXX_STANDARD 17)

set(TOP_DIR ${CMAKE_SOURCE_DIR})
set(SRC_DIR ${TOP_DIR}/src)

set(LIB_NAME matrix)

set(SRC_LIST
        ${SRC_DIR}/Matrix.hpp
        ${SRC_DIR}/Matrix.hxx
        )

add_library(${LIB_NAME} INTERFACE)

target_sources(${LIB_NAME} INTERFACE ${SRC_LIST})

target_include_directories (${LIB_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${SRC_DIR}/${LIB_NAME}>
        $<INSTALL_INTERFACE:${LIB_NAME}>
        )


# executable for quick testing in main.cpp
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${LIB_NAME})

add_executable(lab3a main.cpp src/Matrix.hxx src/Matrix.hpp)