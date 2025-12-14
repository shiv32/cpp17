cmake_minimum_required(VERSION 4.0)
project(ThreadScheduler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thread_scheduler
    main.cpp
    ThreadPool.cpp
)
