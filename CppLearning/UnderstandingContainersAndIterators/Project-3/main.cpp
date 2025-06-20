/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Dynamic-Length vectors
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

    std::vector<double> doubleVector; // Create a vector with zero elements.

    // Initialize max to smallest number
    double max = -std::numeric_limits<double>::infinity();

    for (size_t i = 1; true; i++)
    {
        double temp;

        std::cout << "Enter score " << i << " (-1 to stop): ";

        std::cin >> temp;

        if (temp == -1)
        {
            break;
        }

        doubleVector.push_back(temp);

        if (temp > max)
        {
            max = temp;
        }
    }

    max /= 100.0;

    for (auto &element : doubleVector)
    {
        element /= max;

        std::cout << element;

        if (element != doubleVector.back()) // not Last element
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    return 0;
}