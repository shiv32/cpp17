/*

Objects on the Heap

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    //---------------------- Using the “arrow” operator: -> ---------------------------------
    SpreadsheetCell *myCellp = new SpreadsheetCell();

    myCellp->setValue(3.7);

    std::cout << "cell 1: " << myCellp->getValue() << " " << myCellp->getString() << std::endl;

    delete myCellp;
    myCellp = nullptr;

    //--------------------------- Using dereferencing (*) and member access (.) operator------
    SpreadsheetCell *myCellp2 = new SpreadsheetCell();

    (*myCellp2).setValue(3.7);

    std::cout << "cell 1: " << (*myCellp2).getValue() << " " << (*myCellp2).getString() << std::endl;

    delete myCellp2;
    myCellp2 = nullptr;

    //------------------ Using Smart Pointer --------------------------------------------------
    auto myCellp3 = std::make_unique<SpreadsheetCell>();
    // Equivalent to:
    // std::unique_ptr<SpreadsheetCell> myCellp3(new SpreadsheetCell());

    myCellp3->setValue(3.7);

    std::cout << "cell 1: " << myCellp3->getValue() << " " << myCellp3->getString() << std::endl;

    return 0;
}