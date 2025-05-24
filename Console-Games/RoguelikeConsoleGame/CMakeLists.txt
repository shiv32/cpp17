cmake_minimum_required(VERSION 3.10)
project(RoguelikeConsoleGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add engine folder to include path
include_directories(${CMAKE_SOURCE_DIR}/engine)

# Engine source files
file(GLOB_RECURSE ENGINE_SOURCES "engine/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "engine/*.hpp")

# Main source
set(EXAMPLE_SRC example/main.cpp)

# Build executable
add_executable(roguelike ${ENGINE_SOURCES} ${ENGINE_HEADERS} ${EXAMPLE_SRC})

# Link libraries
target_link_libraries(roguelike ${CURSES_LIBRARIES})
