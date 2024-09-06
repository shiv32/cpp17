cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Add flag to disable copy elision
add_compile_options(-fno-elide-constructors) #in vs studio code debug option mean uncomment this line for elide disable

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
# message("12345 Compile options: ${CMAKE_CXX_FLAGS}")

# Set the project name
project(moveSemantics)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    Integer.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(moveSemantics ${SOURCES})

#target_compile_options(moveSemantics PRIVATE -fno-elide-constructors)

