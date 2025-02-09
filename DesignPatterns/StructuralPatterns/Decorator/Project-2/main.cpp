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
#include "ConcreteComponent.hpp"
#include "ConcreteDecoratorA.hpp"
#include "ConcreteDecoratorB.hpp"
#include <memory>

/**
 * The client code works with all objects using the Component interface. This
 * way it can stay independent of the concrete classes of components it works
 * with.
 */
void ClientCode(Component *component)
{
    std::cout << "RESULT: " << component->Operation();
}

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /**
     * This way the client code can support both simple components...
     */
    // Component *simple = new ConcreteComponent;

    // smart pointer
    auto simple = std::make_unique<ConcreteComponent>();

    std::cout << "Client: I've got a simple component:\n";
    // ClientCode(simple);
    ClientCode(simple.get());
    std::cout << "\n\n";

    /**
     * ...as well as decorated ones.
     *
     * Note how decorators can wrap not only simple components but the other
     * decorators as well.
     */
    // Component *decorator1 = new ConcreteDecoratorA(simple);
    // Component *decorator2 = new ConcreteDecoratorB(decorator1);

    // smart pointer
    auto decorator1 = std::make_unique<ConcreteDecoratorA>(simple.get());
    auto decorator2 = std::make_unique<ConcreteDecoratorB>(decorator1.get());

    std::cout << "Client: Now I've got a decorated component:\n";
    // ClientCode(decorator2);
    ClientCode(decorator2.get());
    std::cout << "\n\n";

    // delete simple;
    // delete decorator1;
    // delete decorator2;

    return 0;
}