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
#include <random>

namespace reverse
{
    void example1()
    {
        std::vector<int> v{1, 2, 3, 4, 5};

        std::reverse(v.begin(), v.end());

        for (int x : v)
            std::cout << x << " ";

        std::cout << "\n";
    }
}

namespace shuffle
{
    void example1()
    {
        std::vector<int> v{1, 2, 3, 4, 5};

        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister

        std::shuffle(v.begin(), v.end(), gen);

        for (int x : v)
            std::cout << x << " ";

        std::cout << "\n";
    }

    void example2()
    {
        std::string s = "ABCDE";

        std::mt19937 gen{std::random_device{}()};

        std::shuffle(s.begin(), s.end(), gen);

        std::cout << s << "\n";
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    reverse::example1();

    shuffle::example1();
    shuffle::example2();

    return 0;
}