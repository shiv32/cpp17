#include "Player.hpp"

Player::Player(int x, int y) : x(x), y(y) {}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Player::getX() const { return x; }
int Player::getY() const { return y; }
