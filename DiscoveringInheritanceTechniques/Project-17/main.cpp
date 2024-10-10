/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Naming Collisions and Ambiguous Base Classes
                It’s not difficult to construct a scenario where multiple inheritance would seem to break down.

        Name Ambiguity

                            Dog [ eat() ]
                                <- \
                                    DogBird
                                <- /
                           Bird [ eat() ]

                What if the Dog class and the Bird class both had a method called eat()? 
                Because Dog and Bird are not related in any way, one version of the method does not override the 
                other—they both continue to exist in the DogBird-derived class.

                If client code attempts to call the eat() method on a DogBird, 
                the compiler gives an error indicating that the call to eat() is ambiguous.
                The compiler does not know which version to call. 

                The solution to the ambiguity is to either explicitly upcast the object using a dynamic_cast(),
                essentially hiding the undesired version of the method from the compiler.
                or to use a disambiguation syntax.

                eg.
                    DogBird myConfusedAnimal;
                    
                    dynamic_cast<Dog&>(myConfusedAnimal).eat(); // Calls Dog::eat()

                    myConfusedAnimal.Dog::eat(); // Calls Dog::eat()
              
                



 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    
    return 0;
}