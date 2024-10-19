/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief INTERESTING AND OBSCURE INHERITANCE ISSUES
            Extending a class opens up a variety of issues. 
                What characteristics of the class can and cannot be changed? 
                What is non-public inheritance? 
                What are virtual base classes? 
                etc.

        Changing the Overridden Method’s Characteristics
            The reason you override a method is to change its implementation. 
            You may want to change other characteristics of the method.

            Changing the Method Return Type
                A good rule of thumb is to override a method with the exact method declaration,
                or method prototype, that the base class uses. 
                The implementation can change, but the prototype stays the same.

                In C++, an overriding method can change the return type as long as the original return type is
                a pointer or reference to a class, and the new return type is a pointer or reference to a 
                descendent class. 
                Such types are called covariant return types. 
                This feature sometimes comes in handy when the base class and derived class work with objects in 
                a parallel hierarchy—that is, another group of classes that is tangential, but related, 
                to the first class hierarchy.

                    eg. cherry orchard simulator

                            You might have two hierarchies of classes that model different real-world objects
                            but are obviously related. 
                            The first is the Cherry chain. The base class, Cherry, has a derived class called BingCherry. 
                            Similarly, there is another chain of classes with a base class called CherryTree
                            and a derived class called BingCherryTree.

                                Cherry <-- BingCherry
                            
                            CherryTree <-- BingCherryTree

                            Now assume that the CherryTree class has a virtual method called pick() 
                            that retrieves a single cherry from the tree:

                                    Cherry* CherryTree::pick()
                                    {
                                        return new Cherry();
                                    }
 
                            In the BingCherryTree-derived class, you may want to override this method.
                            Because a BingCherry is a Cherry, you could leave the method prototype as is 
                            and override the method.
                            The BingCherry pointer is automatically cast to a Cherry pointer. 

                                    Cherry* BingCherryTree::pick()
                                    {
                                        auto theCherry = std::make_unique<BingCherry>();
                                        theCherry->polish();
                                        return theCherry.release();
                                    }







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