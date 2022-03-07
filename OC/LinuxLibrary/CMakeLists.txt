cmake_minimum_required(VERSION 3.21)
project(Showcase)

set(CMAKE_CXX_STANDARD 14)

add_executable(Showcase main.cpp)

add_library(Number Number/Number.cpp)
add_library(Vector SHARED Vector/Vector.cpp)

target_link_libraries(Showcase Number)
target_link_libraries(Showcase Vector)
