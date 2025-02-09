
cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(Decorator)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    A.cpp
    AwithX.cpp
    AwithY.cpp
    AwithZ.cpp
    AwithXY.cpp
    AwithXYZ.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(Decorator ${SOURCES})
