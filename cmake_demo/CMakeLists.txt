cmake_minimum_required(VERSION 3.10)
project(CMakeDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cmake_demo main.cpp math_utils.cpp)
