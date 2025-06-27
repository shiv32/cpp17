/*

Constructors on the Heap

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    auto smartCellp = std::make_unique<SpreadsheetCell>(40);

    // ... do something with the cell, no need to delete the smart pointer
    std::cout << "smartCellp cell 1: " << smartCellp->getValue() << std::endl;


    // Or with raw pointers, without smart pointers (not recommended)
    SpreadsheetCell *myCellp = new SpreadsheetCell(50);

    std::cout << "myCellp cell 1: " << myCellp->getValue() << std::endl;
    
    SpreadsheetCell *anotherCellp = nullptr;
    anotherCellp = new SpreadsheetCell(40);

    // ... do something with the cells
    std::cout << "anotherCellp cell 1: " << anotherCellp->getValue() << std::endl;
   
    delete myCellp;
    myCellp = nullptr;
   
    delete anotherCellp;
    anotherCellp = nullptr;

    return 0;
}