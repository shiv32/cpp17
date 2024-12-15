# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(poco_project VERSION 1.0)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Poco Libraries
find_package(Poco REQUIRED COMPONENTS Foundation Net Util)

# Add the executable
add_executable(http_client main.cpp)

# Link Poco Libraries
target_link_libraries(http_client Poco::Foundation Poco::Net Poco::Util)
