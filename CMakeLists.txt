cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Bank.cpp Bank.h Person.cpp Person.h Bank_sys.cpp Bank_sys.h)
