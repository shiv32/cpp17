cmake_minimum_required(VERSION 3.10)
project(ConsoleGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(console_game
    main.cpp
    engine/Engine.cpp
    game/Game.cpp
    game/Player.cpp
)

target_include_directories(console_game PRIVATE
    engine
    game
)

target_link_libraries(console_game ncurses)
