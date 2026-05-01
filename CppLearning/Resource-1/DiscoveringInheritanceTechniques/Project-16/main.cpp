/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   MULTIPLE INHERITANCE
                Multiple inheritance is often perceived as a complicated and unnecessary
                part of object-oriented programming.
                This section explains the mechanics of multiple inheritance in C++.

            Inheriting from Multiple Classes
                Defining a class to have multiple parent classes is very simple from a syntactic point of view.

                eg.

                    class Baz : public Foo, public Bar
                    {

                    };

                By listing multiple parents, the Baz object has the following characteristics:

                ➤ A Baz object supports the public methods, and contains the data members of both Foo
                and Bar.
                ➤ The methods of the Baz class have access to protected data and methods in both Foo
                and Bar.
                ➤ A Baz object can be upcast to either a Foo or a Bar.
                ➤ Creating a new Baz object automatically calls the Foo and Bar default constructors, in the
                order that the classes are listed in the class definition.
                ➤ Deleting a Baz object automatically calls the destructors for the Foo and Bar classes, in the
                reverse order that the classes are listed in the class definition.

                Another example:

                            Dog
                                <- \
                                    DogBird
                                <- /
                           Bird

                            Using objects of classes with multiple parents is no different from using objects without multiple
                            parents. 
                            In fact, the client code doesn’t even have to know that the class has two parents. 
                            In this case, a DogBird object supports all of the public methods of Dog and Bird.




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

    myConfusedAnimal.bark();
    myConfusedAnimal.chirp();

    return 0;
}