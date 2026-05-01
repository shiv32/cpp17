/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Comparing vectors
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<int> vectorOne(10);
    std::vector<int> vectorTwo(10);

    if (vectorOne == vectorTwo)
    {
        std::cout << "equal!" << std::endl;
    }
    else
    {
        std::cout << "not equal!" << std::endl;
    }

    vectorOne[3] = 50;

    if (vectorOne < vectorTwo)
    {
        std::cout << "vectorOne is less than vectorTwo" << std::endl;
    }
    else
    {
        std::cout << "vectorOne is not less than vectorTwo" << std::endl;
    }

    return 0;
}