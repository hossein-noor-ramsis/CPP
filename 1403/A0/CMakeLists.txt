cmake_minimum_required(VERSION 4.1)
project(A0)

set(CMAKE_CXX_STANDARD 20)

add_executable(A0 main.cpp
        Model/Train.cpp
        Model/Train.h
        Model/Time.cpp
        Model/Time.h
        App.cpp
        App.h
        consts.h
        Utils/String.cpp
        Utils/String.h)
