/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief vector Iterators
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <limits>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<double> doubleVector(5); // Create a vector of 5 doubles.

    // Initialize max to smallest number
    double max = -std::numeric_limits<double>::infinity();

    for (size_t i = 0; i < doubleVector.size(); i++)
    {
        std::cout << "Enter score " << i + 1 << ": ";
        std::cin >> doubleVector[i];

        if (doubleVector[i] > max)
        {
            max = doubleVector[i];
        }
    }

    max /= 100.0;

    // for (auto &element : doubleVector)
    // {
    //     element /= max;

    //     std::cout << element;

    //     if (element != doubleVector.back()) // not Last element
    //     {
    //         std::cout << ", ";
    //     }
    // }

    // for (std::vector<double>::iterator iter = begin(doubleVector); iter != end(doubleVector); ++iter)
    // {
    //     *iter /= max;
    //     std::cout << *iter << " ";

    //     if (*iter != doubleVector.back()) // not Last element
    //     {
    //         std::cout << ", ";
    //     }
    // }

    for (auto iter = begin(doubleVector); iter != end(doubleVector); ++iter)
    {
        *iter /= max;
        std::cout << *iter << " ";

        if (*iter != doubleVector.back()) // not Last element
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    return 0;
}