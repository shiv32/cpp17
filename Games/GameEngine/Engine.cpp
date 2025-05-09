#include "Engine.hpp"
#include "Player.hpp"
#include <iostream>
#include <chrono>
#include <thread>

Engine::Engine() : isRunning(true)
{
    entities.push_back(std::make_shared<Player>());
}

void Engine::run()
{
    while (isRunning)
    {
        handleInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate frame time
    }
}

void Engine::handleInput()
{
    std::cout << "Press Q to quit, any key to continue...\n";
    char ch;
    std::cin >> ch;
    if (ch == 'q' || ch == 'Q')
    {
        isRunning = false;
    }
}

void Engine::update()
{
    for (auto &e : entities)
        e->update();
}

void Engine::render()
{
    for (auto &e : entities)
        e->render();
}
