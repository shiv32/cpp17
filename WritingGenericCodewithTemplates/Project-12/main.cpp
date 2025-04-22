/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Template parameter deduction for constructors

    g++ -std=c++17 main.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-04-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<int> defaultGrid1(67); // default value in each cell is 67 (ie int)
    std::cout << defaultGrid1.at(5, 5).value_or(0) << std::endl;

    Grid defaultGrid2(67); // default value in each cell is 67 (ie int)
    std::cout << defaultGrid2.at(5, 6).value_or(0) << std::endl;

    Grid<double> defaultGrid3(67.6); // default value in each cell is 67.6 (ie double)
    std::cout << defaultGrid3.at(3, 5).value_or(0) << std::endl;

    Grid defaultGrid4(67.6); // default value in each cell is 67.6 (ie double)
    std::cout << defaultGrid4.at(3, 6).value_or(0) << std::endl;

    Grid<int> defaultGrid5(67.6); // default value in each cell is 67 (ie int)
    std::cout << defaultGrid5.at(3, 7).value_or(0) << std::endl;

    //----------------------------
    std::pair<int, double> pair1(1, 2.3);
    std::cout << "(" << pair1.first << ", " << pair1.second << ")\n";

    auto pair2 = std::make_pair(1, 2.3);
    std::cout << "(" << pair2.first << ", " << pair2.second << ")\n";

    std::pair pair3(1, 2.3); // C++17 feature
    std::cout << "(" << pair3.first << ", " << pair3.second << ")\n";

    return 0;
}