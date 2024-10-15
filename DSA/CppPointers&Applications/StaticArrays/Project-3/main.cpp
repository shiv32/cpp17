/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Static Arrays
 *         Array as reference argument
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>

int Print(int *ptr, int size)
{

    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << ' ';
        // or
        // std::cout << *(ptr + i) << ' ';
    }

    std::cout << std::endl;
}

template <typename T, int size>
void Print(T (&ref)[size])
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << ref[i] << ' ';
        // or
        // std::cout << *(ref + i) << ' ';
    }

    std::cout << std::endl;
}

template <typename T, int size>
T *Begin(T (&ref)[size])
{
    return ref;
}

template <typename T, int size>
T *End(T (&ref)[size])
{
    return (ref + size);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr1[5];
    int arr2[5]{};
    // int arr3[5]{1, 2, 3, 4, 5};
    int arr3[5]{3, 1, 6, 8, 0};

    arr3[0] = 100;

    int(&ref)[5] = arr3; // array referene is ref

    // int *p = arr3;
    // int *end = arr3 + 5;
    // or
    // int *p = Begin(arr3);
    // int *end = End(arr3);
    // or
    int *p = std::begin(arr3);
    int *end = std::end(arr3);

    // *(p + 2) = 800;
    // or
    p[2] = 800;

    // *(p + 7) = 800;

    // Print(arr3, sizeof(arr3) / sizeof(int));
    // Print(arr3, 10); // stack smashing detected, Aborted (core dumped)

    // std::sort(p, end);
    // or
    std::sort(std::begin(arr3), std::end(arr3));

    Print(arr3);

    return 0;
}