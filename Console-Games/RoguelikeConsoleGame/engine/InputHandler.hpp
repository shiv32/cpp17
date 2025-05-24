#pragma once
#include "Player.hpp"
#include "Map.hpp"

class InputHandler {
public:
    //void handleInput(int key, Player& player);
     void handleInput(int key, Player& player, const Map& map);
};
