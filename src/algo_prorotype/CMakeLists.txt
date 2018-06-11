cmake_minimum_required(VERSION 3.9)
project(push_swap_prototype)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        push_swap_prototype
        main.cpp
        actionlib/actionlib.h
        algos/algos.h
        actionlib/actionlib.cpp
        algos/test_qsort.cpp
)