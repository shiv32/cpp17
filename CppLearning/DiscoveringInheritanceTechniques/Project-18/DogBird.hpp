#pragma once

#include "Dog.hpp"
#include "Bird.hpp"


class DogBird : public Dog, public Bird
{
public:
    // void eat() override;
     using Dog::eat; // Explicitly inherit Dog's version of eat()
    //using Bird::eat; // Explicitly inherit Bird's version of eat()
};