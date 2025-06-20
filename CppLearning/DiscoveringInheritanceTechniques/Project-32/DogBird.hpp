#pragma once

#include "Dog.hpp"
#include "Bird.hpp"

class DogBird : public Dog, public Bird
{
public:
    virtual void eat() override;
};