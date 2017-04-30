cmake_minimum_required(VERSION 3.5)
project(cs242project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cs242project2 ${SOURCE_FILES})