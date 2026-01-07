/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>

namespace unique
{
    void example1()
    {
        std::vector<int> v{1, 1, 2, 2, 2, 3, 1, 1};

        // It removes consecutive duplicates, not all duplicates.
        auto newEnd = std::unique(v.begin(), v.end());

        v.erase(newEnd, v.end());

        for (int x : v)
            std::cout << x << " ";

        std::cout << "\n";
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    unique::example1();

    return 0;
}