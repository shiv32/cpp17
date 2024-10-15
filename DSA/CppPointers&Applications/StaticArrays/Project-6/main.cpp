/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Static Arrays
 *         Multidimensional Arrays
 *
 * @version 0.1
 * @date 2024-08-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

// void Print(int (*p)[3])
// {
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             std::cout << p[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

void Print2(int (*p)[3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << p[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T, int rows, int columns>
void Print(T (&ref)[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << ref[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int(*p)[3] = arr;
    p[0][0] = 100;

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         std::cout << arr[i][j]<<" ";
    //     }
    //     std::cout << std::endl;
    // }

    // Print(arr);
    // Print2(arr, 2);
    Print(arr);

    return 0;
}