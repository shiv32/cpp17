#include "GameManager.h"
#include "AudioManager.h"
#include <iostream>

GameManager &GameManager::getInstance()
{
    static GameManager instance;
    return instance;
}

void GameManager::run()
{
    AudioManager::getInstance().loadSound("move", "../assets/move.wav");
    AudioManager::getInstance().loadSound("attack", "../assets/attack.wav");

    std::cout << "You are in a dark room.\n";
    std::cout << "Commands: [w] up, [s] down, [a] left, [d] right, [q] quit\n";

    char command;
    while (std::cin >> command)
    {
        if (command == 'q')
            break;
        if (command == 'a')
        {
            std::cout << "[Sound: Attack]\n";
            AudioManager::getInstance().playSound("attack");
        }
        else
        {
            std::cout << "[Sound: Footstep]\n";
            AudioManager::getInstance().playSound("move");
        }
    }

    std::cout << "Game Over.\n";
}
