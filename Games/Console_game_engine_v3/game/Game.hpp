#pragma once
#include "Player.hpp"
#include "Map.hpp"
#include "../ui/UIManager.hpp"

class Game
{
public:
    Game();
    void handleInput(int key);
    void update();
    void render();

private:
    Player player_;
    Map map_;
    UIManager ui_;
};