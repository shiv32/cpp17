/**
 * @file Abstraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Abstraction.hpp"
#include <iostream>

Abstraction::Abstraction(Implementation *implementation) : implementation_(implementation)
{
}

Abstraction::~Abstraction()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string Abstraction::Operation() const
{
    return "Abstraction: Base operation with:\n" + this->implementation_->OperationImplementation();
}
