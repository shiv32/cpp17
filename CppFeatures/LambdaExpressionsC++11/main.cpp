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

template <typename T, int size>
void Sort(T (&arr)[size])
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

    Sort(arr);

    for (auto x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    return 0;
}