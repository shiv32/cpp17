#pragma once
#include "../game/Game.hpp"

class Engine {
public:
    Engine(Game& game);
    void run();
private:
    Game& game_;
    bool isRunning_;
    const int FPS = 30;
    const int FRAME_DURATION_MS = 1000 / FPS;

    void init();
    void shutdown();
};
