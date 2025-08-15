cmake_minimum_required(VERSION 4.0)

project(mini-project-callback)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    math_func.cpp
    main.cpp
)

add_executable(test ${SOURCES})
