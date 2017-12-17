cmake_minimum_required(VERSION 3.9)
project(task_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=100500")
add_executable(task_1 main.cpp)