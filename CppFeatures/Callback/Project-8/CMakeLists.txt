cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(callback)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

# Add an executable with the above sources
add_executable(callback ${SOURCES})

# Add a custom command to generate assembly
add_custom_command(TARGET callback POST_BUILD
    COMMAND ${CMAKE_CXX_COMPILER} -S -masm=intel -g -fverbose-asm -Wa,-adhln ${CMAKE_SOURCE_DIR}/${SOURCES} -o ${CMAKE_BINARY_DIR}/main.s
)