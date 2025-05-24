#include "Game.hpp"
#include <ncurses.h>

Game::Game() : player_(1, 1) {}

void Game::handleInput(int key) {
    player_.handleInput(key, map_);
}

void Game::update() {}

void Game::render() {
    clear();
    map_.render();
    player_.render();
    ui_.render();
    refresh();
}