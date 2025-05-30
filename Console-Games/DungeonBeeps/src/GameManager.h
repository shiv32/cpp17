#pragma once

class GameManager
{
public:
    static GameManager &getInstance();
    void run();

private:
    GameManager() = default;
};
