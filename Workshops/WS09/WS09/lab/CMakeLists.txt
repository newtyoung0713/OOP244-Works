cmake_minimum_required(VERSION 3.27)
project(lab)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(lab
        Book.cpp
        Book.h
        LibraryItem.cpp
        LibraryItem.h
        main.cpp)
