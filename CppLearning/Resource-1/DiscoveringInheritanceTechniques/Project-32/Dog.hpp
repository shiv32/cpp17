#pragma once

#include "Animal.hpp"

// class Dog : public Animal
class Dog : public virtual Animal
{
public:
    virtual void bark();
    virtual void eat() override;
};
