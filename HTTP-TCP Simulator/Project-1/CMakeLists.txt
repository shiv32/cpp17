# Minimum required version of CMake
cmake_minimum_required(VERSION 4.0)

# Project name
project(httpsimulator VERSION 1.0)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Poco Libraries
find_package(Poco REQUIRED COMPONENTS Foundation Net Util)

# Add the executable
add_executable(httpsimulator main2.cpp)

# Link Poco Libraries
target_link_libraries(httpsimulator Poco::Foundation Poco::Net Poco::Util)
