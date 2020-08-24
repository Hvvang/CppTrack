cmake_minimum_required(VERSION 3.1)

project(t00 LANGUAGES CXX)
add_library(utils INTERFACE)
target_include_directories(utils INTERFACE .)
