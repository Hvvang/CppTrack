cmake_minimum_required(VERSION 3.1)

project(t01 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

add_executable(serializer ${SOURCE_EXE})
