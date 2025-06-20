/*
Constructor Initializers part 2

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SomeClass.hpp"

int main()
{
    SomeClass sc(78.5);

    std::cout << "cell 1: " << sc.getSpreadsheetCellinstance().getValue() << std::endl;

    return 0;
}