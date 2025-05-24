cmake_minimum_required(VERSION 3.10)
project(BlockBreaker)

set(CMAKE_CXX_STANDARD 17)  # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable
add_executable(snake_game main.cpp)

# Link ncurses library
target_link_libraries(snake_game ${CURSES_LIBRARIES})
