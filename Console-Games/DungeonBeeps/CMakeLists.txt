cmake_minimum_required(VERSION 3.14)
project(DungeonBeeps)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-graphics sfml-window sfml-system)

add_executable(DungeonBeeps
    src/main.cpp
    src/GameManager.cpp
    src/AudioManager.cpp
)

target_include_directories(DungeonBeeps PRIVATE src)
target_link_libraries(DungeonBeeps sfml-audio)
