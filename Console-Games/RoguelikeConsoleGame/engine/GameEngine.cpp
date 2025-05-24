#include "GameEngine.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

GameEngine::GameEngine() : player(10, 5), renderer(map, player, enemies)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);
    isRunning = true;
    srand(time(0));
    spawnEnemies();
}

GameEngine::~GameEngine()
{
    endwin();
}

void GameEngine::run()
{
    while (isRunning)
    {
        int input = getch();
        if (input == 'q')
        {
            isRunning = false;
            break;
        }

        inputHandler.handleInput(input, player, map);

        update();
        checkCollisions();
        renderer.render();

        // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // slower loop
    }
}

void GameEngine::update()
{
    enemyMoveCooldown++;
    if (enemyMoveCooldown >= 5)
    { // Move enemies every 5 game loops (~250ms if loop delay is 50ms)
        for (auto &enemy : enemies)
        {
            enemy.moveToward(player);
        }
        enemyMoveCooldown = 0;
    }
}

void GameEngine::spawnEnemies()
{
    enemies.clear();
    for (int i = 0; i < 3; ++i)
    {
        int ex, ey;
        do
        {
            ex = 1 + rand() % (map.getData()[0].size() - 2);
            ey = 1 + rand() % (map.getData().size() - 2);
        } while (ex == player.getX() && ey == player.getY());
        enemies.emplace_back(ex, ey);
    }
}

void GameEngine::checkCollisions()
{
    for (auto &enemy : enemies)
    {
        if (enemy.getX() == player.getX() && enemy.getY() == player.getY())
        {
            clear();
            mvprintw(0, 0, "Game Over! You were caught! Press any key to exit.");
            refresh();
            timeout(-1); // wait indefinitely for key press
            getch();
            isRunning = false;
            return;
        }
    }
}
