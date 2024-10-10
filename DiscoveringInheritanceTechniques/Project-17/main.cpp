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

                Methods of the derived class itself can also explicitly disambiguate between different methods of the
                same name by using the same syntax used to access parent methods, that is, the :: scope resolution
                operator.

                        eg.
                            The DogBird class could prevent ambiguity errors in other code by defining
                            its own eat() method.
                            Inside this method, it would determine which parent version to call.

                                class DogBird : public Dog, public Bird
                                {
                                    public:
                                    void eat() override;
                                };

                                void DogBird::eat()
                                {
                                    Dog::eat(); // Explicitly call Dog's version of eat()
                                }

                Yet another way to prevent the ambiguity error is to use a using statement to explicitly
                state which version of eat() should be inherited in DogBird.

                        eg.
                            class DogBird : public Dog, public Bird
                            {
                                public:
                                using Dog::eat; // Explicitly inherit Dog's version of eat()
                            }




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

    // myConfusedAnimal.eat();  // Error! Ambiguous call to method eat()

    // myConfusedAnimal.eat();  // Explicitly call Dog's version of eat() in void DogBird::eat()

    myConfusedAnimal.eat(); // Explicitly inherit Dog's version of eat() by using statement

    // dynamic_cast<Dog &>(myConfusedAnimal).eat(); // Calls Dog::eat()

    // myConfusedAnimal.Bird::eat(); // Calls Bird::eat()

    return 0;
}