cmake_minimum_required(VERSION 3.10)
project(MiniLibProject)

add_subdirectory(maths)
add_subdirectory(logger)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE maths logger)
