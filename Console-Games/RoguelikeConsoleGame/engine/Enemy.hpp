#pragma once
#include "Player.hpp"

class Enemy {
public:
    Enemy(int x, int y);
    void moveToward(const Player& player);
    int getX() const;
    int getY() const;
private:
    int x, y;
};
