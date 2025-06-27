/*

Writing Constructors

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    //------------------ Using Smart Pointer --------------------------------------------------
    auto myCellp3 = std::make_unique<SpreadsheetCell>(3.7);
    // Equivalent to:
    // std::unique_ptr<SpreadsheetCell> myCellp3(new SpreadsheetCell());

    std::cout << "cell 1: " << myCellp3->getValue() << " " << myCellp3->getString() << std::endl;

    return 0;
}