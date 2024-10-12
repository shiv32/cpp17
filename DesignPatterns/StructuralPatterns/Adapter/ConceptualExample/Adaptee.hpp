/**
 * @file Adaptee.hpp
 * @author your name (you@domain.com)
 * @brief 
 * 

 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 
 * 
 * 
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>

class Adaptee
{
public:
    std::string SpecificRequest() const;
};