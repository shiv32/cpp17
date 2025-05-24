#pragma once
#include <vector>
#include <memory>
#include "Entity.hpp"

class Engine
{
public:
    Engine();
    void run();

private:
    bool isRunning;
    std::vector<std::shared_ptr<Entity>> entities;

    void handleInput();
    void update();
    void render();
};
