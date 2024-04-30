/*

Default Constructor

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    //default constructor on the stack
    SpreadsheetCell myCell;
    myCell.setValue(6);
    std::cout << "cell 1: " << myCell.getValue() << std::endl;

    //heap-based object allocation
    auto smartCellp = std::make_unique<SpreadsheetCell>();
    smartCellp->setValue(63);
    std::cout << "cell 2: " << smartCellp->getValue() << std::endl;

    //Or with a raw pointer (not recommended)
    SpreadsheetCell *myCellp = new SpreadsheetCell();
    //Or
    //SpreadsheetCell* myCellp = new SpreadsheetCell;

    myCellp->setValue(64);
    std::cout << "cell 3: " << myCellp->getValue() << std::endl;
    
    delete myCellp;
    myCellp = nullptr;

    return 0;
}