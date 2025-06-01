cmake_minimum_required(VERSION 3.14)
project(musicPlayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt MOC
#set(CMAKE_AUTOMOC ON)   # Needed if you use Q_OBJECT macro (e.g., in custom QObject subclasses). 
                        #This enables automatic invocation of the Meta-Object Compiler (MOC).
#set(CMAKE_AUTORCC ON) # for .qrc files for embedding resources like images or sounds.
#set(CMAKE_AUTOUIC ON) # for .ui files (used in GUI apps with Qt Widgets).

# Optional: Set the path to your Qt installation if it's not system-wide
#set(CMAKE_PREFIX_PATH "/home/userName/Qt/5.9.9/gcc_64") #set your Qt path here if install by qt online installer

find_package(Qt5 REQUIRED COMPONENTS Multimedia)

add_executable(musicPlayer
    main.cpp
)

target_link_libraries(musicPlayer
    Qt5::Multimedia
)
