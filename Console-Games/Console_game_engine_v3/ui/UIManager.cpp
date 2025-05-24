#include "UIManager.hpp"
#include <ncurses.h>

void UIManager::render() const
{
    mvprintw(11, 0, "[Arrows] Move | [q] Quit");
}