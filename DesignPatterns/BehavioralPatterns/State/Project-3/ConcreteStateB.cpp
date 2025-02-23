/**
 * @file ConcreteStateB.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ConcreteStateB.h"
#include <iostream>
#include "ConcreteStateA.h"

State *ConcreteStateB::Handle()
{
	std::cout << "[ConcreteStateB] State B behavior\n";
	return new ConcreteStateA{};
}
