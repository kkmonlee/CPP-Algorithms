cmake_minimum_required(VERSION 3.5)
project(Projects_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp "Sorting algorithms/bogo.cpp")
add_executable(Projects_C ${SOURCE_FILES} "Sorting algorithms/bogo.cpp")