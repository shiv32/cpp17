/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Run-Time Type Facilities
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <typeinfo>

#include "Dog.hpp"
#include "Bird.hpp"

void speak(const Animal &animal)
{

    if (typeid(animal) == typeid(Dog))
    {

        std::cout << "Woof!" << std::endl;
    }
    else if (typeid(animal) == typeid(Bird))
    {

        std::cout << "Chirp!" << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Dog dog;
    speak(dog);

    Bird bird;
    speak(bird);

    return 0;
}