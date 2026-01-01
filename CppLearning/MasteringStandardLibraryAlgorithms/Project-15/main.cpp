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

namespace ca
{
    // all_of()
    void example1()
    {
        std::vector<int> vec2 = {1, 1, 1, 1};

        if (all_of(cbegin(vec2), cend(vec2), [](int i){ return i == 1; }))
        {
            std::cout << "All elements are == 1" << std::endl;
        }
        else
        {
            std::cout << "Not all elements are == 1" << std::endl;
        }
    }

    // any_of()
    void example2()
    {
        std::vector<int> vec3 = {0, 0, 1, 0};

        if (any_of(cbegin(vec3), cend(vec3), [](int i){ return i == 1; }))
        {
            std::cout << "At least one element == 1" << std::endl;
        }
        else
        {
            std::cout << "No elements are == 1" << std::endl;
        }
    }

    // none_of()
    void example3()
    {
        std::vector<int> vec4 = {0, 0, 0, 0};

        if (none_of(cbegin(vec4), cend(vec4), [](int i){ return i == 1; }))
        {
            std::cout << "All elements are != 1" << std::endl;
        }
        else
        {
            std::cout << "Some elements are == 1" << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ca::example1();
    ca::example2();
    ca::example3();

    return 0;
}