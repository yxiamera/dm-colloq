cmake_minimum_required(VERSION 3.8)
project(dm_colloc)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
add_executable(dm_colloc main.cpp)
target_link_libraries(dm_colloc gtest)