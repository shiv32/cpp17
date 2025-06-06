cmake_minimum_required(VERSION 3.16)
project(QtStateMachineApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(QAbstractTableModel main.cpp)
target_link_libraries(QAbstractTableModel Qt5::Core)
