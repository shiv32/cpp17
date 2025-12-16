cmake_minimum_required(VERSION 3.10)
project(TaskTimerCLI)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(TaskTimer
    main.cpp
    taskmanager.cpp
    taskmanager.hpp
)

target_link_libraries(TaskTimer Qt5::Core)
