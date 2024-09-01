/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   std::array
                C++ provides a very thin wrapper over a C-style array called
                std::array.
                std::array automates the allocation and deallocation of memory.
                std::array is a templatized class that takes two parameters:
                the type of the elements and
                the size ofthe array.



 * @version 0.1
 * @date 2024-09-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <array>

// void print(std::array<int, 5> arr)
// {
//     for (auto ele : arr)
//     {
//         std::cout << ele << ", ";
//     }
// }

template <size_t N>
void print(const std::array<int, N> &arr)
{
    for (auto ele : arr)
    {
        std::cout << ele << ", ";
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //-------------------------------------------------------------------------

    std::array<int, 10> arr; // array of int of size 10

    arr[0] = 1; // Sets the first element as 1

    std::cout << "First element: " << arr[0] << std::endl;

    std::array<int, 4> arr2 = {1, 2, 3, 4};

    //-------------------------------------------------------------------------

    std::cout << "Elements in second array: ";

    for (int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";

    std::cout << std::endl;
    //-------------------------------------------------------------------------

    // try
    // {
    //     std::cout << arr2.at(4); // No error
    //     std::cout << arr2.at(5); // Throws exception std::out_of_range
    // }
    // catch (const std::out_of_range &ex)
    // {
    //     std::cerr << "caught exception : " << ex.what();
    // }

    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    print(arr3);

    std::array<int, 7> arr4 = {1, 2, 3, 4, 5, 6, 7};
    print(arr4);
    //---------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    std::array<int, 5> arr5 = {1, 2, 3, 4, 5};

    // for (auto element : arr5)
    // {
    //     std::cout << element << ' ';
    // }

    for (auto it = arr5.begin(); it != arr5.end(); it++)
    {
        auto element = (*it);
        std::cout << element << ' ';
    }
     std::cout << std::endl;
    //---------------------------------------------------------------------------

    //----------------------------------------------------------------------------
    std::array<int, 5> arr6 = {1, 2, 3, 4, 5};

    std::cout << arr6.front() << std::endl;       // Prints 1
    std::cout << arr6.back() << std::endl;        // Prints 5
    std::cout << *(arr6.data() + 1) << std::endl; // Prints 2
    //----------------------------------------------------------------------------

    std::cout << std::endl;

    return 0;
}