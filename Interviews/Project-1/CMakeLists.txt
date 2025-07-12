cmake_minimum_required(VERSION 3.5)
project(cppInterview)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "*.cpp")

add_executable(cppInterview ${SOURCES})
