cmake_minimum_required(VERSION 4.4)

project(MURDOKU_SOLVER VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main src/main.cpp src/Board.cpp)

target_compile_options(main PRIVATE
-Wall -Wextra -Wpedantic -Wsign-conversion)

target_include_directories(main PUBLIC include)
