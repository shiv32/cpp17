#include <ncurses.h>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    initscr();
    printw("Hello, ncurses!");
    refresh();
    getch();
    endwin();
    return 0;
}
