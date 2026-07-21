cmake_minimum_required(VERSION 3.16)

project(PX4Hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(MAVSDK REQUIRED)

qt_standard_project_setup()

qt_add_executable(PX4HelloApp
    main.cpp
    backend/Drone.cpp
)

qt_add_resources(PX4HelloApp resources
    PREFIX "/"
    FILES
        Main.qml
)

target_include_directories(PX4HelloApp PRIVATE backend)

target_link_libraries(PX4HelloApp PRIVATE
    Qt6::Quick
    MAVSDK::mavsdk
)
