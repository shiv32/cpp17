/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <list>

template <typename... Types> // parameter pack called Types
class MyVariadicTemplate
{
};

// To avoid instantiating a variadic template with zero template arguments.
template <typename T1, typename... Types> // parameter pack called Types
class MyVariadicTemplate2
{
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MyVariadicTemplate<int> instance1;
    MyVariadicTemplate<std::string, double, std::list<int>> instance2;

    MyVariadicTemplate<> instance3; // instantiated with zero template arguments.
    // MyVariadicTemplate2<> instance4; // error: wrong number of template arguments (0, should be at least 1)

    return 0;
}