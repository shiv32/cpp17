
cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(Project14)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    MyClass.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(Project14 ${SOURCES})
