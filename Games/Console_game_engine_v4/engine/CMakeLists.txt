add_library(ConsoleEngine
    src/Engine.cpp
)

target_include_directories(ConsoleEngine PUBLIC include)
target_link_libraries(ConsoleEngine ncurses)