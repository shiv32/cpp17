#include "GameEngine.hpp"
#include <iostream>
#include <exception>

int main()
{
    try
    {
        GameEngine game;
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
