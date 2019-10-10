cmake_minimum_required(VERSION 3.12)
project(P2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P2
        LLQ.cpp
        LLQ.h
        P2.cpp
        stlQ.cpp
        stlQ.h)
