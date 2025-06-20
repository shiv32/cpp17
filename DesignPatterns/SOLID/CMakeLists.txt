cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(solid)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    dip.cpp
    # isp.cpp
    # lsp.cpp
    # ocp.cpp
    # srp.cpp
)

# Add an executable with the above sources
add_executable(solid ${SOURCES})
