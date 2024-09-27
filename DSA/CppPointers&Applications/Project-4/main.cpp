/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Static Arrays
 *         Array as function argument
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int print(int *ptr, int size)
{

    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << ' ';
        // or
        // std::cout << *(ptr + i) << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr1[5];
    int arr2[5]{};
    int arr3[5]{1, 2, 3, 4, 5};

    arr3[0] = 100;

    int *p = arr3;

    // *(p + 2) = 800;
    *(p + 7) = 800;

    // print(arr3, sizeof(arr3) / sizeof(int));
    print(arr3, 10); //stack smashing detected, Aborted (core dumped)

    return 0;
}