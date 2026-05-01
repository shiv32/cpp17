#pragma once

#include <iostream>
#include  "Animal.hpp"

class Dog : public Animal
{
public:
   virtual void bark();
    virtual void eat() override;
};