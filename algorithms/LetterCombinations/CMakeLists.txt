cmake_minimum_required(VERSION 3.5)
project(LetterCombinations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Solution.cpp Solution.h)
add_executable(LetterCombinations ${SOURCE_FILES})