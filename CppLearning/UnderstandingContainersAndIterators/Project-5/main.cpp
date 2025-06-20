/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Copying and Assigning vectors
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //-----------------------------------------------------------------
    std::vector<int> intVector(10);

    std::cout << "vector default value zero : ";
    size_t counter = 0;

    for (auto &element : intVector)
    {
        std::cout << element;

        if (counter != intVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }

    std::cout << std::endl;

    intVector.assign(5, 100);
    std::cout << "vector assign() : ";
    counter = 0;

    for (auto &element : intVector)
    {
        std::cout << element;

        if (counter != intVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;
    //--------------------------------------------------------------------------------------------

    intVector.assign({1, 2, 3, 4});
    std::cout << "vector assign() with initializer_list : ";

    counter = 0;

    for (auto &element : intVector)
    {
        std::cout << element;

        if (counter != intVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;
    //---------------------------------------------------------------------------------------------

    std::vector<int> vectorOne(10);
    std::cout << "vectorOne : ";
    counter = 0;

    for (auto &element : vectorOne)
    {
        std::cout << element;

        if (counter != vectorOne.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;

    std::vector<int> vectorTwo(5, 100);
    std::cout << "vectorTwo : ";

    counter = 0;

    for (auto &element : vectorTwo)
    {
        std::cout << element;

        if (counter != vectorTwo.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;

    vectorOne.swap(vectorTwo);
    // vectorOne now has 5 elements with the value 100.
    // vectorTwo now has 10 elements with the value 0.

    std::cout << "after swap vectorOne : ";
    counter = 0;

    for (auto &element : vectorOne)
    {
        std::cout << element;

        if (counter != vectorOne.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;

    std::cout << "after swap vectorTwo : ";
    counter = 0;

    for (auto &element : vectorTwo)
    {
        std::cout << element;

        if (counter != vectorTwo.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }
        ++counter;
    }
    std::cout << std::endl;
    //-------------------------------------------------------------------

    return 0;
}