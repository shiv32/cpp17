cmake_minimum_required(VERSION 3.10)
project(TaskFlowManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/States/*.cpp")

add_executable(TaskFlowManager ${SOURCES})