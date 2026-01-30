cmake_minimum_required(VERSION 4.0)
project(opencv_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED core imgcodecs imgproc)

add_executable(opencv_demo main.cpp)

target_link_libraries(opencv_demo
    PRIVATE
    opencv_core
    opencv_imgcodecs
    opencv_imgproc
)
