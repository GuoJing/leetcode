cmake_minimum_required(VERSION 3.5)
project(MergeTwoLst)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp listnode.h listnode.cpp solution.cpp solution.h)
add_executable(MergeTwoLst ${SOURCE_FILES})