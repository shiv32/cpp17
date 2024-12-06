/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Test-1

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

void Print()
{
    std::cout << std::endl;
}

template <typename T, typename... params>
void Print(T &&a, params &&...args)
{
    std::cout << a;

    if (sizeof...(args) != 0)
    {
        std::cout << ", ";
    }

    Print(std::forward<params>(args)...);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Print(1, 3.4, "Y");

    return 0;
}