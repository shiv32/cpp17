#include "InputHandler.hpp"
#include <ncurses.h>

void InputHandler::handleInput(int key, Player& player, const Map& map) {
    int newX = player.getX();
    int newY = player.getY();

    switch (key) {
        case KEY_UP:    newY--; break;
        case KEY_DOWN:  newY++; break;
        case KEY_LEFT:  newX--; break;
        case KEY_RIGHT: newX++; break;
        default: return;
    }

    // Check map bounds and if the tile is walkable ('.')
    if (newY < 0 || newY >= (int)map.getData().size() ||
        newX < 0 || newX >= (int)map.getData()[0].size())
        return;

    if (map.getData()[newY][newX] == '.') {
        player.move(newX - player.getX(), newY - player.getY());
    }
}
