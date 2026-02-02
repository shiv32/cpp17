# cmake_minimum_required(VERSION 4.0)
# project(DungeonBeeps)

# set(CMAKE_CXX_STANDARD 17)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(SFML REQUIRED sfml-graphics sfml-window sfml-system)

# add_executable(DungeonBeeps
#     src/main.cpp
#     src/GameManager.cpp
#     src/AudioManager.cpp
# )

# target_include_directories(DungeonBeeps PRIVATE src)
# target_link_libraries(DungeonBeeps sfml-audio)
################################################################

cmake_minimum_required(VERSION 4.0)
project(DungeonBeeps LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# SFML 2 uses shared libraries by default
set(SFML_STATIC_LIBRARIES OFF)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(DungeonBeeps
    src/main.cpp
    src/GameManager.cpp
    src/AudioManager.cpp
)

target_link_libraries(DungeonBeeps
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)
