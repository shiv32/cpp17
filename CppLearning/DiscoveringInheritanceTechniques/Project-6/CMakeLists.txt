cmake_minimum_required(VERSION 3.5)

# Set the compiler
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(PreventingOverriding)

set(CMAKE_CXX_FLAGS -pthread)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    Base.cpp
    Derived.cpp
    Derived1.cpp
    Derived2.cpp
    DerivedDerived.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(PreventingOverriding ${SOURCES})
