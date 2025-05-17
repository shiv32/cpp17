cmake_minimum_required(VERSION 3.10)
project(TradingSimApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
)

# Header files
include_directories(src)

# Create executable
add_executable(TradingSim ${SOURCES})
