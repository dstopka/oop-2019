cmake_minimum_required(VERSION 3.14)
project(02_cmake)

set(CMAKE_CXX_STANDARD 17)

include_directories(../googletest/googletest/include)
link_directories(../googletest/build/lib)
add_library(dummy STATIC dummy.cpp dummy.h)

add_executable(02_cmake main.cpp)
target_link_libraries(02_cmake dummy)

add_executable(02_cmake_test test.cpp)
target_link_libraries(02_cmake_test gtest gtest_main pthread dummy)
