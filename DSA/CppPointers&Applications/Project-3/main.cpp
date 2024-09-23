/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Static Arrays
 *              Arrays basics & Example of static Arrays
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr1[5];
    int arr2[5]{};
    int arr3[5]{1, 2, 3, 4, 5};

    arr3[0] = 100;

    int *p = arr3;

    *(p + 2) = 800;

    return 0;
}