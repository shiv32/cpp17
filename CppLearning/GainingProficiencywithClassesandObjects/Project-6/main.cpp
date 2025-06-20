/*

Objects on the Stack

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{

    SpreadsheetCell myCell, anotherCell;
    
    myCell.setValue(6);
    
    anotherCell.setString("3.2");
    
    std::cout << "cell 1: " << myCell.getValue() << std::endl;
    std::cout << "cell 2: " << anotherCell.getValue() << std::endl;

    return 0;
}