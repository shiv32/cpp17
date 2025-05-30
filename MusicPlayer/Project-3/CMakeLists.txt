cmake_minimum_required(VERSION 3.14)
project(musicPlayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Optional: Set the path to your Qt installation if it's not system-wide
set(CMAKE_PREFIX_PATH "/home/userName/Qt/5.9.9/gcc_64") #set your Qt path here

find_package(Qt5 REQUIRED COMPONENTS Multimedia)

add_executable(musicPlayer
    main.cpp
)

target_link_libraries(musicPlayer
    Qt5::Multimedia
)
