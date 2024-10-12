/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
        Adapter using Multiple inheritance
            g++ *.cpp -o test
 *
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Adapter.hpp"

/**
 * The client code supports all classes that follow the Target interface.
 */
// void ClientCode(const Target *target)
// {
//     std::cout << target->Request();
// }

// using smart pointer
void ClientCode(std::shared_ptr<Target> target)
{
    std::cout << target->Request();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::cout << "Client: I can work just fine with the Target objects:\n";

    // Target *target = new Target;
    // ClientCode(target);

    // std::cout << "\n\n";

    // Adaptee *adaptee = new Adaptee;
    // std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    // std::cout << "Adaptee: " << adaptee->SpecificRequest();
    // std::cout << "\n\n";
    // std::cout << "Client: But I can work with it via the Adapter:\n";

    // Adapter *adapter = new Adapter;
    // ClientCode(adapter);
    // std::cout << "\n";

    // delete target;
    // delete adaptee;
    // delete adapter;

    //---------------------(using smart pointer)------------------------------
    std::cout << "Client: I can work just fine with the Target objects:\n";

    auto target = std::make_shared<Target>();
    ClientCode(target);

    std::cout << std::endl
              << std::endl;

    auto adaptee = std::make_shared<Adaptee>();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << std::endl
              << std::endl;
    std::cout << "Client: But I can work with it via the Adapter:\n";

    auto adapter = std::make_shared<Adapter>();
    ClientCode(adapter);
    std::cout << std::endl;

    return 0;
}
