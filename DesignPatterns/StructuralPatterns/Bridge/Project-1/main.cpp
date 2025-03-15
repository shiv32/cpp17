/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Bridge
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Abstraction.hpp"
#include "ExtendedAbstraction.hpp"
#include "ConcreteImplementationA.hpp"
#include "ConcreteImplementationB.hpp"

/**
 * Except for the initialization phase, where an Abstraction object gets linked
 * with a specific Implementation object, the client code should only depend on
 * the Abstraction class. This way the client code can support any abstraction-
 * implementation combination.
 */
void ClientCode(const Abstraction &abstraction)
{
    std::cout << abstraction.Operation();
}

/**
 * The client code should be able to work with any pre-configured abstraction-
 * implementation combination.
 */
int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Implementation *implementation = new ConcreteImplementationA;
    // Abstraction *abstraction = new Abstraction(implementation);
    // ClientCode(*abstraction);
    // delete implementation;
    // delete abstraction;

    // std::cout << std::endl;

    // implementation = new ConcreteImplementationB;
    // abstraction = new ExtendedAbstraction(implementation);
    // ClientCode(*abstraction);
    // delete implementation;
    // delete abstraction;

    // using smart pointer
    std::unique_ptr<Implementation> implementation = std::make_unique<ConcreteImplementationA>();
    std::unique_ptr<Abstraction> abstraction = std::make_unique<Abstraction>(implementation.get());
    ClientCode(*abstraction.get());

    std::cout << std::endl;

    implementation = std::make_unique<ConcreteImplementationB>();
    abstraction = std::make_unique<ExtendedAbstraction>(implementation.get());
    ClientCode(*abstraction.get());

    return 0;
}