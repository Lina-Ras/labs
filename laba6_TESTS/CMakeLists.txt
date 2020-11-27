cmake_minimum_required(VERSION 3.16)
project(laba6)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(Fraction)
include_directories(Fraction)

file(GLOB tests "test/*.cpp")

add_executable(laba6 ${tests})
#add_executable(laba6 main.cpp)
target_link_libraries(laba6 Fraction gtest gtest_main)