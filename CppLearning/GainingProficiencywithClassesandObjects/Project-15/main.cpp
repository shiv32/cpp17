/*

Explicitly Defaulted Constructors 
Explicitly Deleted Constructors

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    SpreadsheetCell myCell;
    myCell.setValue(60);
    std::cout << "cell 1: " << myCell.getValue() << std::endl;

    return 0;
}