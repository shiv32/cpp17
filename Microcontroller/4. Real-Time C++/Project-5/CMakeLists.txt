cmake_minimum_required(VERSION 4.0)

project(realTimeCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "*.cpp")

add_executable(realTimeCpp ${SOURCES})
