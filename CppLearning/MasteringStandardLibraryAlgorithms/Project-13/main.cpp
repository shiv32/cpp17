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

namespace bms
{
    std::string text = "This is the haystack to search a needle in.";
    std::string toSearchFor = "needle";

    void example1()
    {
        auto searcher = std::boyer_moore_searcher(cbegin(toSearchFor), cend(toSearchFor));

        auto result = search(cbegin(text), cend(text), searcher);

        if (result != cend(text))
        {
            std::cout << "Found the needle." << std::endl;
        }
        else
        {
            std::cout << "Needle not found." << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    bms::example1();

    return 0;
}