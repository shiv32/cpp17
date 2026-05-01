/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Run-Time Type Facilities
 *            One of the primary values of the typeid operator is for logging and debugging purposes.
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <typeinfo>
#include "Foo.hpp"

void logObject(const Loggable &loggableObject)
{
    std::cout << typeid(loggableObject).name() << ": ";
    std::cout << loggableObject.getLogMessage() << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Foo foo;
    logObject(foo);

    return 0;
}