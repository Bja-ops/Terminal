cmake_minimum_required(VERSION 3.30)
project(projekty)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekty main.cpp)

target_link_libraries(projekty winmm)

