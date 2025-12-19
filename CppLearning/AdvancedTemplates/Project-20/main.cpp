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

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << std::conjunction_v<std::is_integral<int>, std::is_integral<short>> << " ";
    
    std::cout << std::conjunction_v<std::is_integral<int>, std::is_integral<double>> << " ";

    std::cout << std::disjunction_v<std::is_integral<int>, std::is_integral<double>, std::is_integral<short>> << " ";

    std::cout << std::negation_v<std::is_integral<int>> << " ";

    std::cout << std::endl;

    return 0;
}