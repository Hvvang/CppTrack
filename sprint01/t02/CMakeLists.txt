cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(visitAll)
add_subdirectory(src)
add_executable(visitAll main.cpp)
target_link_libraries(visitAll PUBLIC visit)
target_include_directories(visitAll PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src"
                          )
