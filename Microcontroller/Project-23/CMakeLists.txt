cmake_minimum_required(VERSION 3.10)
project(mock_stm32_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/stm32_hal_mock)
include_directories(${CMAKE_SOURCE_DIR}/logic)

# Source files
add_executable(mock_stm32
    main.cpp
)
