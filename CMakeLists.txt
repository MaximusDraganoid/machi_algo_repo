cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp source/division.cpp headers/math_func.h headers/util_function.h source/util_function.cpp headers/burnikel_zigler.h source/burnikel_zigler.cpp source/add.cpp source/add.cpp source/compare_common.cpp source/difference.cpp source/multiplication.cpp headers/math_func_big_osn.h source/add_big_osn.cpp source/multiplication_big_osn.cpp source/difference_big_osn.cpp source/division_big_osn.cpp)
