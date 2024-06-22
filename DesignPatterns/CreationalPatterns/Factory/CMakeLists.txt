
cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(Factory)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    ConcreteProduct1.cpp
    ConcreteProduct2.cpp
    ConcreteCreator1.cpp
    ConcreteCreator2.cpp
    Creator.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(Factory ${SOURCES})
