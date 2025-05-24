#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "Enemy.hpp"
#include <vector>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

private:
    bool isRunning;
    Map map;
    Player player;
    std::vector<Enemy> enemies;
    InputHandler inputHandler;
    Renderer renderer;

    void update();
    void checkCollisions();
    void spawnEnemies();

    int enemyMoveCooldown = 0;

};
