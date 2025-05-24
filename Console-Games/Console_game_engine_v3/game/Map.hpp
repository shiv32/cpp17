#pragma once

class Map
{
public:
    Map();
    void render() const;
    bool isBlocked(int x, int y) const;

private:
    static const int width = 20;
    static const int height = 10;
    char tiles_[height][width];
};