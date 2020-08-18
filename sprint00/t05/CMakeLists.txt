set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(autonaton main.cpp)
