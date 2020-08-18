set(SRC ./src)
set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(inventory main.cpp ${SRC}/exitCommand.cpp ${SRC}/helpCommand.cpp
               ${SRC}/removeCommand.cpp ${SRC}/showCommand.cpp
               ${SRC}/insertCommand.cpp ${SRC}/inventory.h
               ${SRC}/commandManager.cpp)
