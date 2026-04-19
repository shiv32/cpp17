cmake_minimum_required(VERSION 4.0)

# Set the project name
project(iocpp)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES main.cpp)

# Add an executable with the above sources
add_executable(iocpp ${SOURCES})
