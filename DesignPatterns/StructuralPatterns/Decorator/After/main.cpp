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
#include "A.hpp"
#include "X.hpp"
#include "Y.hpp"
#include "Z.hpp"
#include <memory>

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // I *anX = new X(new A);
    // I *anXY = new Y(new X(new A));
    // I *anXYZ = new Z(new Y(new X(new A)));

    // smart pointer
    auto anX = std::make_unique<X>(new A);
    auto anXY = std::make_unique<Y>(new X(new A));
    auto anXYZ = std::make_unique<Z>(new Y(new X(new A())));

    anX->do_it();
    std::cout << '\n';

    anXY->do_it();
    std::cout << '\n';

    anXYZ->do_it();
    std::cout << '\n';

    // delete anX;
    // delete anXY;
    // delete anXYZ;

    return 0;
}