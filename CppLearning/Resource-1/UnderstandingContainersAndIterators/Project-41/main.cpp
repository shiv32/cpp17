/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Strings
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

void stringDemo()
{
    std::string myString;

    myString.insert(cend(myString), 'h');
    myString.insert(cend(myString), 'e');

    myString.push_back('l');
    myString.push_back('l');
    myString.push_back('o');

    for (const auto &letter : myString)
    {
        std::cout << letter;
    }

    std::cout << std::endl;

    for (auto it = cbegin(myString); it != cend(myString); ++it)
    {
        std::cout << *it;
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    stringDemo();

    return 0;
}
