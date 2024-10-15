/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Static Arrays
 *         Multidimensional Arrays on Heap
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <ctime>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /**
     1,2,3
     4,5,6

     *p1->1,2,3
     *p2->4,5,6

     **pp->p1,p2

     pp[0][0] == 1

     */

    srand(time(NULL));

    int **pp = new int *[2];

    pp[0] = new int[3];
    pp[1] = new int[3];

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            pp[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << pp[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    delete[] pp[0];
    delete[] pp[1];
    delete[] pp;

    return 0;
}