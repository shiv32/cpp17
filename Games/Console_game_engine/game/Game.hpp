#pragma once
#include "Player.hpp"

class Game {
public:
    Game();
    void handleInput(int key);
    void update();
    void render();
private:
    Player player_;
};
