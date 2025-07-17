cmake_minimum_required(VERSION 3.10)
project(Qt5CLIApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(Qt5CLIApp main.cpp)
target_link_libraries(Qt5CLIApp Qt5::Core)
