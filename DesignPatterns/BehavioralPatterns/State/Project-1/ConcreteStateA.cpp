/**
 * @file ConcreteStateA.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ConcreteStateA.hpp"
#include "ConcreteStateB.hpp"

void ConcreteStateA::Handle1()
{
    std::cout << "ConcreteStateA handles request1.\n";
    std::cout << "ConcreteStateA wants to change the state of the context.\n";

    this->context_->TransitionTo(new ConcreteStateB);
}

void ConcreteStateA::Handle2()
{
    std::cout << "ConcreteStateA handles request2.\n";
}