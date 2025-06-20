#pragma once

#include "Animal.hpp"

// class Bird : public Animal
class Bird : public virtual Animal
{
public:
    virtual void chirp();
    virtual void eat() override;
};