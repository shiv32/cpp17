#include <iostream>
#include "Spreadsheet.hpp"

void unaryMinusEx()
{
    Spreadsheet s1(4, 3);

    SpreadsheetCell c1(4);
    SpreadsheetCell c3 = -c1; // Unary minus

    s1.setCellAt(2, 1, c1);
    s1.setCellAt(2, 0, c3);

    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;
    std::cout << "Cell value at (2,0): " << s1.getCellAt(2, 0).getValue() << std::endl;
}

void unaryPlusEx()
{
    Spreadsheet s1(4, 3);

    SpreadsheetCell c1(4);
    SpreadsheetCell c3 = +c1; // Unary plus

    s1.setCellAt(2, 1, c1);
    s1.setCellAt(2, 0, c3);

    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;
    std::cout << "Cell value at (2,0): " << s1.getCellAt(2, 0).getValue() << std::endl;
}

void incrementEx()
{
    Spreadsheet s1(4, 3);

    SpreadsheetCell c1(4);
    SpreadsheetCell c2(4);

    // c1++; Postfix
    s1.setCellAt(2, 1, c1++);
    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;

    //++c2; Prefix
    s1.setCellAt(2, 0, ++c2);
    std::cout << "Cell value at (2,0): " << s1.getCellAt(2, 0).getValue() << std::endl;
}

void decrementEx()
{
    Spreadsheet s1(4, 3);

    SpreadsheetCell c1(4);
    SpreadsheetCell c2(4);

    // c1--; Postfix
    s1.setCellAt(2, 1, c1--);
    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;

    //--c2; Prefix
    s1.setCellAt(2, 0, --c2);
    std::cout << "Cell value at (2,0): " << s1.getCellAt(2, 0).getValue() << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // unaryMinusEx();
    // unaryPlusEx();
    // incrementEx();
    decrementEx();

    return 0;
}