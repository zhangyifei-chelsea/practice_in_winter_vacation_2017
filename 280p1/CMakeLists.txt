cmake_minimum_required(VERSION 3.6)
project(280_p1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp triangle.h triangle.cpp palindrome.h palindrome.cpp power.cpp power.h abundant.cpp abundant.h)
add_executable(280_p1 ${SOURCE_FILES})