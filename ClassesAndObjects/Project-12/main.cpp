/*

Providing Multiple Constructors

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell aThirdCell("test");                     // Uses string-arg ctor
    SpreadsheetCell aFourthCell(4.4);                       // Uses double-arg ctor
    auto aFifthCellp = std::make_unique<SpreadsheetCell>("5.5"); // string-arg ctor

    std::cout << "aThirdCell: " << aThirdCell.getValue() << std::endl;
    std::cout << "aFourthCell: " << aFourthCell.getValue() << std::endl;
    std::cout << "aFifthCellp: " << aFifthCellp->getValue() << std::endl;

    return 0;
}