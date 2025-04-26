/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Facade.hpp"
#include "Subsystem1.hpp"
#include "Subsystem2.hpp"

void ClientCode(Facade *facade)
{
    std::cout << facade->Operation();
}

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
    Subsystem1 *subsystem1 = new Subsystem1;
    Subsystem2 *subsystem2 = new Subsystem2;
    Facade *facade = new Facade(subsystem1.get(), subsystem2.get());
    ClientCode(facade);
    delete facade;
    */

    // using smart pointer
    auto subsystem1 = std::make_unique<Subsystem1>();
    auto subsystem2 = std::make_unique<Subsystem2>();
    auto facade = std::make_unique<Facade>(subsystem1.get(), subsystem2.get());

    ClientCode(facade.get());

    return 0;
}