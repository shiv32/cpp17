cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(thread)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

# Add an executable with the above sources
add_executable(thread ${SOURCES})

# Check if linking with -latomic is required
include(CheckLibraryExists)
check_library_exists(atomic __atomic_load_8 "" HAVE_LIBATOMIC)

if(HAVE_LIBATOMIC)
    target_link_libraries(thread atomic)
endif()
