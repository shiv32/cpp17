/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Lambda Expressions C++11
 *
        compile and run -->
        g++ -std=c++17 main.cpp -o test && ./test && rm test

 *
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

// template <typename T, int size>
// void Sort(T (&arr)[size])
// {
//     for (int i = 0; i < size - 1; ++i)
//     {
//         for (int j = 0; j < size - 1; ++j)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 T temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// template <typename T, int size>
// void Sort(T (&arr)[size])
// {
//     for (int i = 0; i < size - 1; ++i)
//     {
//         for (int j = 0; j < size - 1; ++j)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 T temp = std::move(arr[j]);
//                 arr[j] = std::move(arr[j + 1]);
//                 arr[j + 1] = std::move(temp);
//             }
//         }
//     }
// }

using Comparator = bool (*)(int, int);

template <typename T, int size>
void Sort(T (&arr)[size], Comparator comp)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (comp(arr[j], arr[j + 1]))
            {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(temp);
            }
        }
    }
}

bool CompAsc(int x, int y)
{
    return x > y;
}

bool CompDes(int x, int y)
{
    return x < y;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------(Callbacks revisited - function pointers )------------------
    int arr[]{1, 6, 8, 4, 0};

    for (auto x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    // Sort(arr);
    // Sort(arr,CompAsc);
    Sort(arr, CompDes);

    for (auto x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    return 0;
}