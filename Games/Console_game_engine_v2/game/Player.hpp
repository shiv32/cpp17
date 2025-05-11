#pragma once

class Player {
public:
    Player(int x, int y);
    void handleInput(int key);
    void render();
private:
    int x_, y_;
};
