cmake_minimum_required(VERSION 3.6)
project(gjd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BigNumber.cpp)
add_executable(gjd ${SOURCE_FILES})