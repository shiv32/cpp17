/**
 * @file ExtendedAbstraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ExtendedAbstraction.hpp"
#include <iostream>

ExtendedAbstraction::ExtendedAbstraction(Implementation *implementation) : Abstraction(implementation)
{
}

ExtendedAbstraction::~ExtendedAbstraction() 
{
     //std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string ExtendedAbstraction::Operation() const
{
    return "ExtendedAbstraction: Extended operation with:\n" + this->implementation_->OperationImplementation();
}