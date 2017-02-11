cmake_minimum_required(VERSION 3.6)
project(gjd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BigNumber.cpp)
add_executable(gjd ${SOURCE_FILES})

set(SOURCE_FILES unittest.cpp BigNumber.cpp)
add_executable(gjd_test ${SOURCE_FILES})
target_link_libraries(gjd_test gtest)