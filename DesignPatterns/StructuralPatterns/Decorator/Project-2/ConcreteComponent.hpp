#pragma once

#include "Component.hpp"

/**
 * Concrete Components provide default implementations of the operations. There
 * might be several variations of these classes.
 */
class ConcreteComponent : public Component
{
public:
    ~ConcreteComponent();
    std::string Operation() const override;
   
};