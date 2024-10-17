cmake_minimum_required(VERSION 3.5)

# Set the compiler
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Disable optimizations (-O0), enable debug information (-g)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

# Set the project name
project(inlinefun)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

# Add an executable with the above sources
add_executable(inlinefun ${SOURCES})
