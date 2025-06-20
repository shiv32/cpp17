/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
    Basic template demo

    g++ main.cpp -o test
 * 
 * 
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <iostream>

template <typename T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << findMax(2, 4) << std::endl;

    std::cout << findMax(4.6f, 8.3f) << std::endl;

    return 0;
}