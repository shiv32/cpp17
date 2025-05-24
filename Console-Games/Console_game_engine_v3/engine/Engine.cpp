#include "Engine.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>

Engine::Engine(Game &game) : game_(game), isRunning_(true) {}

void Engine::init()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void Engine::shutdown()
{
    endwin();
}

void Engine::run()
{
    init();

    while (isRunning_)
    {
        auto start = std::chrono::high_resolution_clock::now();

        int ch = getch();
        if (ch == 'q')
            isRunning_ = false;

        game_.handleInput(ch);
        game_.update();
        game_.render();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if (duration.count() < FRAME_DURATION_MS)
            std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DURATION_MS - duration.count()));
    }

    shutdown();
}