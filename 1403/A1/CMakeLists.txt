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
        View/DefaultView.cpp
        View/DefaultView.h
        View/ErrorView.cpp
        View/ErrorView.h
        View/ListView.cpp
        View/ListView.h
        Model/OfferedCourse.cpp
        Model/OfferedCourse.h
        Model/TakenCourse.cpp
        Model/TakenCourse.h
        Controller/OfferedCoursesController.cpp
        Controller/OfferedCoursesController.h
        Controller/TakenCoursesController.cpp
        Controller/TakenCoursesController.h
)