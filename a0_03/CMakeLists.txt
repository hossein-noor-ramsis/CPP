cmake_minimum_required(VERSION 4.1)
project(a0_03)

set(CMAKE_CXX_STANDARD 20)

add_executable(a0_03 main.cpp
        Model/Train.cpp
        Model/Train.h
        Model/Time.cpp
        Model/Time.h
        App.cpp
        App.h)
