cmake_minimum_required(VERSION 3.31)
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
        Utils/String.h
        DB.h
        Controller/TrainController.cpp
        Controller/TrainController.h
        Controller/TicketController.cpp
        Controller/TicketController.h
        View/DefaultView.cpp
        View/DefaultView.h
        View/ErrorView.cpp
        View/ErrorView.h
        View/ListView.cpp
        View/ListView.h
)
