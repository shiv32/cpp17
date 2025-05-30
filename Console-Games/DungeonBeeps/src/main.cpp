#include <iostream>
#include "GameManager.h"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    GameManager::getInstance().run();
    
    return 0;
}
