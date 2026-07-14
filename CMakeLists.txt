cmake_minimum_required(VERSION 4.4)

project(MURDOKU_SOLVER VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(murdoku src/main.cpp)

target_compile_options(murdoku PRIVATE
-Wall -Wextra -Wpedantic -Wsign-conversion)

target_include_directories(murdoku PUBLIC include)
