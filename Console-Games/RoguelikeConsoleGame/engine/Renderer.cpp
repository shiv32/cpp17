#include "Renderer.hpp"
#include <ncurses.h>

Renderer::Renderer(Map& m, Player& p, std::vector<Enemy>& e) : map(m), player(p), enemies(e) {}

void Renderer::render() {
    clear();
    auto data = map.getData();
    for (size_t y = 0; y < data.size(); ++y) {
        mvprintw(y, 0, "%s", data[y].c_str());
    }
    mvaddch(player.getY(), player.getX(), '@');
    for (const auto& enemy : enemies) {
        mvaddch(enemy.getY(), enemy.getX(), 'E');
    }
    refresh();
}
