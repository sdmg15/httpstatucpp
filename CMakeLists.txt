cmake_minimum_required(VERSION 3.10)

project(httpStatucpp)

set(CMAKE_CXX_STANDARD 17)


set (CMAKE_BINARY_DIR build)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(httpStatucpp main.cpp StatusCode.hpp StatusCode.cpp)

target_link_libraries(httpStatucpp ${CONAN_LIBS})


