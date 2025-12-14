cmake_minimum_required(VERSION 4.0)
project(LogProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(log_processor
    main.cpp
    LogQueue.cpp
)
