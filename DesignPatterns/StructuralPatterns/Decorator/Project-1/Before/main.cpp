/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief without Decorator
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "AwithX.hpp"
#include "AwithXY.hpp"
#include "AwithXYZ.hpp"

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    AwithX anX;
    AwithXY anXY;
    AwithXYZ anXYZ;

    anX.do_it();
    std::cout << '\n';

    anXY.do_it();
    std::cout << '\n';

    anXYZ.do_it();
    std::cout << '\n';

    return 0;
}