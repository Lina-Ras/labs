cmake_minimum_required(VERSION 3.16)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(Student)
include_directories(Student)

file(GLOB tests "test/*.cpp")

add_executable(lab7 ${tests})
#add_executable(lab7 main.cpp)
target_link_libraries(lab7 Student gtest gtest_main)