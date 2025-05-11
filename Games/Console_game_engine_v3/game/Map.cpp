#include "Map.hpp"
#include <ncurses.h>

Map::Map()
{
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            tiles_[y][x] = (x == 0 || y == 0 || x == width - 1 || y == height - 1) ? '#' : '.';
}

void Map::render() const
{
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            mvaddch(y, x, tiles_[y][x]);
}

bool Map::isBlocked(int x, int y) const
{
    return tiles_[y][x] == '#';
}