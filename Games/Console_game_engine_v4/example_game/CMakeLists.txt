add_executable(example_game
    src/main.cpp
    src/Game.cpp
    src/Map.cpp
    src/Player.cpp
    ui/UIManager.cpp
)

target_include_directories(example_game PRIVATE src ui)
target_link_libraries(example_game ConsoleEngine)