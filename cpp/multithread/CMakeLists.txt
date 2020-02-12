cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)
add_executable(cpp multithread.cpp)
target_link_libraries (myapp ${CMAKE_THREAD_LIBS_INIT})
