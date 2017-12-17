cmake_minimum_required(VERSION 3.9)
project(task_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-inline-functions -O0")
add_executable(VectorList VectorList.cpp VectorList.h)

add_executable(task_1 main.cpp VectorList)