/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

inline int square1(int x)
{
    return x * x;
}

int square2(int x)
{
    return x * x;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    int num = 5;

    std::cout << "Square of " << num << " is " << square1(num) << std::endl; // Inline function call
    std::cout << "Square of " << num << " is " << square2(num) << std::endl; // Normal function call

    return 0;
}