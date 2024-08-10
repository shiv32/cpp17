/**
 * @file Adapter.hpp
 * @author your name (you@domain.com)
 * @brief 
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

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target
{
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee);
    std::string Request() const override;
};