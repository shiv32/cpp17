/**
 * @file Adapter.hpp
 * @author your name (you@domain.com)
 * @brief 
 * 
        The Adapter makes the Adaptee's interface compatible with the Target's
        interface using multiple inheritance.
 * 
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <algorithm> // for std::reverse
#include "Target.hpp"
#include "Adaptee.hpp"

class Adapter : public Target, public Adaptee
{
public:
    Adapter();
    std::string Request() const override;
};
