cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(uniqueWords)
add_subdirectory(src)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC UniqueWords)
target_include_directories(${PROJECT_NAME} PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src"
                          )
