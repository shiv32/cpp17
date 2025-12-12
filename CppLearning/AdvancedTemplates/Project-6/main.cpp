/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "oneDGrid.hpp"

using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    OneDGrid<int> singleDGrid;
    OneDGrid<OneDGrid<int>> twoDGrid;
    OneDGrid<OneDGrid<OneDGrid<int>>> threeDGrid;

    singleDGrid[3] = 5;
    twoDGrid[3][3] = 5;
    threeDGrid[3][3][3] = 5;

    std::clog << singleDGrid[3] << std::endl;
    std::clog << twoDGrid[3][3] << std::endl;
    std::clog << threeDGrid[3][3][3] << std::endl;

    return 0;
}