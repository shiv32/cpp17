/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template Method
 * @version 0.1
 * @date 2024-08-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Context.hpp"
#include "ConcreteStrategyA.hpp"
#include "ConcreteStrategyB.hpp"

void clientCode()
{
    /*
    Context context(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();

    std::cout << "\n";

    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();
    */

    // using smart pointers

    auto context = std::make_unique<Context>(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->doSomeBusinessLogic();

    std::cout << "\n";

    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->set_strategy(std::make_unique<ConcreteStrategyB>());
    context->doSomeBusinessLogic();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    clientCode();

    return 0;
}