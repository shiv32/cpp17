cmake_minimum_required(VERSION 3.16)
project(MyQtModelApp)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt MOC
set(CMAKE_AUTOMOC ON)   # Needed if you use Q_OBJECT macro (e.g., in custom QObject subclasses). 
                        #This enables automatic invocation of the Meta-Object Compiler (MOC).
#set(CMAKE_AUTORCC ON) # for .qrc files for embedding resources like images or sounds.
#set(CMAKE_AUTOUIC ON) # for .ui files (used in GUI apps with Qt Widgets).

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
