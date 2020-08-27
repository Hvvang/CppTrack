cmake_minimum_required(VERSION 3.1)

project(t00 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)

include_directories(../utils)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

add_executable(vector ${SOURCE_EXE})
