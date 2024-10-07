/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Static Arrays
 *         Heap-based Arrays
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>

void Print(int *p, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << p[i] << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int *p = new int[5]{5, 1, 7, 2, 8};

    int *pTemp = new int[5 + 5];

    std::copy(p, p + 5, pTemp);

    delete[] p;

    p = pTemp;

    p[5] = 100;

    Print(p, 6);

    delete[] p;

    return 0;
}