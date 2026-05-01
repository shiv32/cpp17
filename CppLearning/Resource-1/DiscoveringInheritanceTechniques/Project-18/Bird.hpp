#pragma once

#include <iostream>
#include  "Animal.hpp"

class Bird : public Animal
{
public:
    virtual void chirp();
    virtual void eat() override;
};