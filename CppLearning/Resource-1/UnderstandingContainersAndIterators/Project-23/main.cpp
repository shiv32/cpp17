/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief array
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <array>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Create an array of 3 integers and initialize them
    // with the given initializer_list using uniform initialization.
    std::array<int, 3> arr = {9, 8, 7};

    // Output the size of the array.
    std::cout << "Array size = " << arr.size() << std::endl; // or std::size(arr);

    // Output the contents using a range-based for loop.
    for (const auto &i : arr)
    {
        std::cout << i << std::endl;
    }

    std::cout << "Performing arr.fill(3)..." << std::endl;

    // Use the fill method to change the contents of the array.
    arr.fill(3);

    // Output the contents of the array using iterators.
    for (auto iter = cbegin(arr); iter != cend(arr); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    std::array<int, 3> myArray{11, 22, 33};

    std::cout << "retrieve an element at the given index 1..." << std::endl;

    // retrieve an element from an std::array at the given index n
    std::cout << std::get<1>(myArray) << std::endl;

    // std::cout << std::get<10>(myArray) << std::endl; // Compilation error!

    return 0;
}