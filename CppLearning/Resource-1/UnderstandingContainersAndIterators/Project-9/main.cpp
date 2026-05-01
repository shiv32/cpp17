/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief const_iterator
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

    std::vector<std::string> stringVector(10, "hello");

    // for (auto it = begin(stringVector); it != end(stringVector); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }

    // for (auto iter = cbegin(stringVector); iter != cend(stringVector); ++iter)
    // {
    //      std::cout << *iter << std::endl;
    // }

    for (const auto &element : stringVector)
    {
        std::cout << element << std::endl;
    }

    return 0;
}