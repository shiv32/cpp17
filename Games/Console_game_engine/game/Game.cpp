#include "Game.hpp"
#include <ncurses.h>

Game::Game() : player_(10, 10) {}

void Game::handleInput(int key) {
    player_.handleInput(key);
}

void Game::update() {
    // Future logic
}

void Game::render() {
    clear();
    player_.render();
    mvprintw(0, 0, "Use arrow keys to move. Press 'q' to quit.");
    refresh();
}
