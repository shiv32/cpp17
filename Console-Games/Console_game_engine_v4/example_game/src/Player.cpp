#include "Player.hpp"
#include <ncurses.h>

Player::Player(int x, int y) : x_(x), y_(y) {}

void Player::handleInput(int key, const Map& map) {
    int newX = x_, newY = y_;
    switch (key) {
        case KEY_UP: newY--; break;
        case KEY_DOWN: newY++; break;
        case KEY_LEFT: newX--; break;
        case KEY_RIGHT: newX++; break;
    }
    if (!map.isBlocked(newX, newY)) {
        x_ = newX;
        y_ = newY;
    }
}

void Player::render() const {
    mvaddch(y_, x_, '@');
}