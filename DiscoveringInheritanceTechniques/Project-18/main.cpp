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