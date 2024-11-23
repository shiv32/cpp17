cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Add compiler flags for assembly output
# if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -S -o main.s")  # GCC/Clang: Generate .s file
# elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FA")          # MSVC: Generate .asm file
# endif()

# Set the project name
project(templates)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

# Add an executable with the above sources
add_executable(templates ${SOURCES})
