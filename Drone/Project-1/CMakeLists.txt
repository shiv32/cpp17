cmake_minimum_required(VERSION 3.16)

project(PX4Hello)

set(CMAKE_CXX_STANDARD 17)

find_package(MAVSDK REQUIRED)

add_executable(px4
    main.cpp
)

target_link_libraries(px4
    MAVSDK::mavsdk
)