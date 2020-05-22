cmake_minimum_required(VERSION 3.10)

project(singleton)

find_package(Threads)

add_executable(singleton singleton_test.cpp)

target_link_libraries(singleton ${CMAKE_THREAD_LIBS_INIT})