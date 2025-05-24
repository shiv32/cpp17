#pragma once
#include "GameInterface.hpp"

class Engine
{
public:
    Engine(GameInterface &game);
    void run();

private:
    GameInterface &game_;
    bool isRunning_;
    const int FPS = 30;
    const int FRAME_DURATION_MS = 1000 / FPS;

    void init();
    void shutdown();
};