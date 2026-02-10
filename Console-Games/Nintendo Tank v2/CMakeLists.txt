cmake_minimum_required(VERSION 4.0)
project(nt)

set(CMAKE_CXX_STANDARD 17)  # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SFML 2 uses shared libraries by default
set(SFML_STATIC_LIBRARIES OFF)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executable
add_executable(nt 
    main.cpp
    AudioManager.cpp
    )

target_link_libraries(nt
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

