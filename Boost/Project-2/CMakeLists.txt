# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(boost_project VERSION 1.0)

# Require C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Add the executable
add_executable(test_boost main.cpp)

# Link Boost libraries
target_link_libraries(test_boost PRIVATE Boost::filesystem Boost::system)
