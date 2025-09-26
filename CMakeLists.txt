cmake_minimum_required(VERSION 3.31)
project(oopd_assignment1_2025_daryna_danyliuk)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oopd_assignment1_2025_daryna_danyliuk
        Board.cpp
        Board.h
        main.cpp
        Shape.h
        Rectangle.cpp
        Rectangle.h
        Shape.cpp
        Circle.cpp
        Circle.h
        Triangle.cpp
        Triangle.h
        Diamond.cpp
        Diamond.h
)
