#pragma once
#include "Map.hpp"

class Player {
public:
    Player(int x, int y);
    void handleInput(int key, const Map& map);
    void render() const;
private:
    int x_, y_;
};