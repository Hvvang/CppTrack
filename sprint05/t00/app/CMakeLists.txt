cmake_minimum_required(VERSION 3.1)

project(t00 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)

add_subdirectory(src)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(draugr ${SOURCE_EXE})
target_link_libraries(draugr src)
