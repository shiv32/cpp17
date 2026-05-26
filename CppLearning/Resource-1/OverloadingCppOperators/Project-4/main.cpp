#include <iostream>
#include "Spreadsheet.hpp"
using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // OVERLOADING THE INSERTION AND EXTRACTION OPERATORS
    SpreadsheetCell myCell, anotherCell, aThirdCell;

    cout << "Extraction" << endl;
    // cin >> myCell >> anotherCell >> aThirdCell; //shorthand form
    operator>>(operator>>(operator>>(cin, myCell), anotherCell), aThirdCell);

    cout << "Insertion" << endl;
    // cout << myCell << " " << anotherCell << " " << aThirdCell << endl; //shorthand form
    // endl(operator<<(operator<<(operator<<(operator<<(operator<<(cout, myCell), " "), anotherCell), " "), aThirdCell)); //std::endl(std::cout);
    operator<<(operator<<(operator<<(operator<<(operator<<(operator<<(cout, myCell), " "), anotherCell), " "), aThirdCell), "\n");

    return 0;
}