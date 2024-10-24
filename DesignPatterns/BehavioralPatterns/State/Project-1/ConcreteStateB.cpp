/**
 * @file ConcreteStateB.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ConcreteStateB.hpp"
#include "ConcreteStateA.hpp"

void ConcreteStateB::Handle1() 
{
    std::cout << "ConcreteStateB handles request1.\n";
}
void ConcreteStateB::Handle2() 
{
    std::cout << "ConcreteStateB handles request2.\n";
    std::cout << "ConcreteStateB wants to change the state of the context.\n";
    this->context_->TransitionTo(new ConcreteStateA);
}