/**
 * @file Adapter.hpp
 * @author your name (you@domain.com)
 * @brief 
 * 
 * 
        The Adapter makes the Adaptee's interface compatible with the Target's
        interface.
 * 
 * 
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <algorithm> // for std::reverse
#include <memory>
#include "Target.hpp"
#include "Adaptee.hpp"

class Adapter : public Target
{
private:
    //Adaptee *adaptee_;
    std::shared_ptr<Adaptee> adaptee_;

public:
    // Adapter(Adaptee *adaptee);
    Adapter(std::shared_ptr<Adaptee> adaptee);

    std::string Request() const override;
};