#include "Engine.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Engine game;
    game.run();
    return 0;
}
