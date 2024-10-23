
cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(State)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    # State.cpp
    # Context.cpp
    # ConcreteStateA.cpp
    # ConcreteStateB.cpp
    #main.cpp
    test_main.cpp
)

# Add an executable with the above sources
add_executable(State ${SOURCES})
