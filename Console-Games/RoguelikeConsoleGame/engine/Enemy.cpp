#include "Enemy.hpp"
#include <cmath>

Enemy::Enemy(int x, int y) : x(x), y(y) {}

void Enemy::moveToward(const Player& player) {
    if (x < player.getX()) x++;
    else if (x > player.getX()) x--;
    if (y < player.getY()) y++;
    else if (y > player.getY()) y--;
}

int Enemy::getX() const { return x; }
int Enemy::getY() const { return y; }
