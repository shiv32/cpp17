cmake_minimum_required(VERSION 3.16)
project(QtMocExample VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(QtMocExample main.cpp)
target_link_libraries(QtMocExample Qt5::Core)





