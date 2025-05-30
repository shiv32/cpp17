cmake_minimum_required(VERSION 3.10)
project(MP3ConsolePlayer)

set(CMAKE_CXX_STANDARD 17)

# Add include and library paths manually
include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu)

# Find PortAudio manually
find_library(PORTAUDIO_LIB portaudio REQUIRED)

add_executable(mp3player main.cpp)

# Link directly to mpg123 and portaudio
target_link_libraries(mp3player
    mpg123
    ${PORTAUDIO_LIB}
)
