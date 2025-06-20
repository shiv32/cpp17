/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Template typeid

    g++ main.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-03-14
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

template <typename T>
T findMax(T a, T b)
{
    std::cout << "Template type : " << typeid(T).name() << std::endl;

    return (a > b) ? a : b;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << findMax(2, 4) << std::endl;

    std::cout << findMax(4.6f, 8.3f) << std::endl;

    std::cout << findMax('A', 'B') << std::endl;

    std::cout << findMax("A", "B") << std::endl;//wrong return

    return 0;
}