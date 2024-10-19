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