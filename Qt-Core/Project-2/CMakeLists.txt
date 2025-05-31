cmake_minimum_required(VERSION 3.16)
project(MyQtModelApp)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt
find_package(Qt5 REQUIRED COMPONENTS Core)

# Add sources (no need to list headers)
add_executable(MyQtModelApp
    main.cpp
    mymodel.cpp
    mymodel.hpp
)

# Link Qt libraries
target_link_libraries(MyQtModelApp Qt5::Core)
