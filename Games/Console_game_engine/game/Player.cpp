#include "Player.hpp"
#include <ncurses.h>

Player::Player(int x, int y) : x_(x), y_(y) {}

void Player::handleInput(int key) {
    switch (key) {
        case KEY_UP:    y_--; break;
        case KEY_DOWN:  y_++; break;
        case KEY_LEFT:  x_--; break;
        case KEY_RIGHT: x_++; break;
    }
}

void Player::render() {
    mvaddch(y_, x_, '@');
}
