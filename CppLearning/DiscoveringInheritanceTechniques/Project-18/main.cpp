/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Ambiguous Base Classes
                Another way to provoke ambiguity is to inherit from the same class twice.

                        eg.
                            If the Bird class inherits from Dog for some reason, the code for DogBird does not
                            compile because Dog becomes an ambiguous base class.

                            class Dog {};
                            class Bird : public Dog {};
                            class DogBird : public Bird, public Dog {}; // Error!


                                Bird <-- DogBird
                                /
                            Dog
                                \
                                DogBird

                Ambiguity can also occur with data members.
                If Dog and Bird both had a data member with the same name,
                an ambiguity error would occur when client code attempted to access that member.

                Multiple parents themselves have common parents.

                        eg.
                            Perhaps both Bird and Dog are inheriting from an
                            Animal class.

                                Dog <-- DogBird
                                /
                            Animal
                                \
                                Bird <-- DogBird

                            Name ambiguity:
                            If the Animal class has a public method called sleep(), that method cannot be called
                            on a DogBird object because the compiler does not know whether to call the version
                            inherited by Dog or by Bird.

                            The best way to use these “diamond-shaped” class hierarchies is to make the topmost class
                            an abstract base class with all methods declared as pure virtual.

                            Because the class only declares methods without providing definitions,
                            there are no methods in the base class to call and thus there are no
                            ambiguities at that level.

                            A diamond-shaped class hierarchy in which the Animal abstract base class has 
                            a pure virtual eat() method that must be defined by each derived class. 
                            The DogBird class still needs to be explicit about which parent’s eat()
                            method it uses, but any ambiguity is caused by Dog and Bird having the same method,
                            not because they inherit from the same class.

            Uses for Multiple Inheritance
                The most straightforward use case for multiple inheritance is to define a class
                of objects that is-a something and also is-a something else.

                One of the most compelling and simple uses of multiple inheritance is for the implementation of
                mixin classes.       

                Another reason that people sometimes use multiple inheritance is to model a component-based class.

                 eg. an airplane simulator
                            The Airplane class has an engine, a fuselage, controls, and other components.

                            While the typical implementation of an Airplane class would make each of these 
                            components a separate data member, you could use multiple inheritance.
                             
                            The airplane class would inherit from engine, fuselage, and controls, in effect 
                            getting the behaviors and properties of all of its components.  

                            I recommend you to stay away from this type of code because it confuses a clear 
                            has-a relationship with inheritance, which should be used for is-a relationships. 
                            The recommended solution is to have an Airplane class that contains data members 
                            of type Engine, Fuselage, and Controls.             


 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "DogBird.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    DogBird myConfusedAnimal;

    myConfusedAnimal.eat(); // Explicitly inherit Dog's version of eat() by using statement

    return 0;
}