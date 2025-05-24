#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <vector>

class Renderer {
public:
    Renderer(Map& map, Player& player, std::vector<Enemy>& enemies);
    void render();
private:
    Map& map;
    Player& player;
    std::vector<Enemy>& enemies;
};
