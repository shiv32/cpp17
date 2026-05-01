/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "NameDB.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    try
    {
        NameDB boys("boys_long.txt");

        std::cout << boys.getNameRank("Daniel") << std::endl;
        std::cout << boys.getNameRank("Jacob") << std::endl;
        std::cout << boys.getNameRank("William") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
