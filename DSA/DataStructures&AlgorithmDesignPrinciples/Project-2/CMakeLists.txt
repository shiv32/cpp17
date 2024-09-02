cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(StdArray)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main3.cpp
)

# Add an executable with the above sources
add_executable(StdArray ${SOURCES})

# Enable sanitizers
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SANITIZERS "-fsanitize=address,undefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZERS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SANITIZERS}")
endif()

# Optionally set more debug flags
set(CMAKE_BUILD_TYPE Debug)
