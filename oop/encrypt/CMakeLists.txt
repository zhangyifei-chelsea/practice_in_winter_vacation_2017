cmake_minimum_required(VERSION 3.6)
project(encrypt)

set(CMAKE_CXX_STANDARD 14)

include_directories(../../lib/md5)

set(SOURCE_FILES main.cpp Cipher.cpp)
add_executable(encrypt ${SOURCE_FILES})
target_link_libraries(encrypt md5)