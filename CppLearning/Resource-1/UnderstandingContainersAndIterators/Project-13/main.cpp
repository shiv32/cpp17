/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Emplace Operations
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

    std::vector<std::string> vec;

    vec.push_back(std::string(5, 'a')); // triggers a call to the move version

    vec.emplace_back(5, 'a'); // to put into place, does not copy or move anything.

    for (auto const &element : vec)
    {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    return 0;
}