cmake_minimum_required(VERSION 3.1)

project(t05 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)

#add_subdirectory(src)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(Werewolf ${SOURCE_EXE})
#target_link_libraries(Werewolf src)
