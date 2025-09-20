cmake_minimum_required(VERSION 4.0)

project(MyApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myapp
    src/main.cpp
    src/MyApp.cpp
)

target_include_directories(myapp PRIVATE include)
