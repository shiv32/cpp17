#pragma once

class Player {
public:
    Player(int x, int y);
    void move(int dx, int dy);
    int getX() const;
    int getY() const;
private:
    int x, y;
};
