cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp impl/math_func.cpp impl/math_func.h impl/util_function.h impl/util_function.cpp burnikel_zigler_division/function.h burnikel_zigler_division/function.cpp)
