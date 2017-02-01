cmake_minimum_required(VERSION 3.6)
project(md5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES md5.cpp)
add_library(md5 ${SOURCE_FILES})