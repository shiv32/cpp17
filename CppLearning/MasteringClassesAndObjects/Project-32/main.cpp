/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    BUILDING STABLE INTERFACES

        Classes are the main unit of abstraction in C++.

        You should apply the principles of abstraction to your classes to separate the interface
        from the implementation as much as possible.

        You should make all data members private and provide getter and setter methods for them.
        This is how the SpreadsheetCell class is implemented.

    Using Interface and Implementation Classes

        An alternative to separating the implementation from the interface is to use an abstract interface.
           An interface with only pure virtual methods and then have an implementation class that implements
           that interface


*/

#include "Spreadsheet.hpp"
#include "AbstractSpreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--------------------------------------------------" << std::endl;

    std::shared_ptr<AbstractSpreadsheet> s1 = std::make_shared<Spreadsheet>(2, 2);
    std::shared_ptr<AbstractSpreadsheet> s2 = std::make_shared<Spreadsheet>(4, 3);

    std::cout << "s1 Width : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height : " << s1->getHeight() << std::endl;

    s1 = s2;

    std::cout << "s1 Width after assignment : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1->getHeight() << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}