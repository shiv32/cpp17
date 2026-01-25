#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell("61.8");
    std::cout << myCell.getValue() << std::endl;

    return 0;
}