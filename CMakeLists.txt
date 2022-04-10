cmake_minimum_required(VERSION 3.0)
project(linalg VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-O3")

include_directories("include/")
add_executable(linalg src/main.cpp)