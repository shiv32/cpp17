cmake_minimum_required(VERSION 3.10)
project(sensor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main2.cpp
)

# Header files
include_directories(src)

# Create executable
add_executable(sensor ${SOURCES})
