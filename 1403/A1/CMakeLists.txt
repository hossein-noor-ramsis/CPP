cmake_minimum_required(VERSION 4.1)
project(A1)

set(CMAKE_CXX_STANDARD 26)

add_executable(A1 main.cpp
        App.cpp
        App.h
        consts.h
        Utils/String.cpp
        Utils/String.h
        DB.h
        Views/DefaultView.cpp
        Views/DefaultView.h
        Views/ErrorView.cpp
        Views/ErrorView.h
        Views/ListView.cpp
        Views/ListView.h
        Models/OfferedCourse.cpp
        Models/OfferedCourse.h
        Models/TakenCourse.cpp
        Models/TakenCourse.h
        Controllers/OfferedCoursesController.cpp
        Controllers/OfferedCoursesController.h
        Controllers/TakenCoursesController.cpp
        Controllers/TakenCoursesController.h
        Utils/Math.cpp
        Utils/Math.h
)