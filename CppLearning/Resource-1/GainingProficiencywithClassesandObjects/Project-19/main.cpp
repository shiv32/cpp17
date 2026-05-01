
#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(61.8);
    SpreadsheetCell myCell2(myCell); // myCell2 has the same values as myCell

    std::cout << myCell2.getValue() << std::endl;

    return 0;
}