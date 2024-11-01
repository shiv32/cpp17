/*
User-defined deduction guide

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "spreadsheetcell.hpp"

int main()
{

    std::string myString = "Hello World!";

    SpreadsheetCell cell(myString);

    std::cout << cell.getContent() << std::endl;

    SpreadsheetCell cell2("Hello World 2!"); // const char *

    std::cout << cell2.getContent() << std::endl;

    return 0;
}