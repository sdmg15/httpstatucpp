cmake_minimum_required(VERSION 3.10)

project(httpstatucpp)

set(CMAKE_CXX_STANDARD 17)


set (CMAKE_BINARY_DIR build)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(tests)
add_executable(httpstatucpp main.cpp StatusCode.hpp StatusCode.cpp)

target_link_libraries(httpstatucpp ${CONAN_LIBS})


