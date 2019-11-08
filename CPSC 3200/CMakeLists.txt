cmake_minimum_required(VERSION 3.14)
project(CPSC_3200)

set(CMAKE_CXX_STANDARD 14)

include_directories(P2)
include_directories(P2/backup)

add_executable(CPSC_3200
        P2/backup/IntDiv.cpp
        P2/backup/IntDiv.h
        P2/backup/P2.cpp
        P2/backup/rangeDiv.cpp
        P2/backup/rangeDiv.h
        P2/intDiv.cpp
        P2/intDiv.h
        P2/P2.cpp
        P2/rangeDiv.cpp
        P2/rangeDiv.h)
