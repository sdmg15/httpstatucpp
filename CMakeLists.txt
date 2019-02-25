cmake_minimum_required(VERSION 3.13)

project(httpStatucpp)

set(CMAKE_CXX_STANDARD 14)


set (CMAKE_BINARY_DIR build)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(database)
add_executable(httpStatucpp main.cpp libs/CLI11.hpp StatusCode.hpp StatusCode.cpp)



