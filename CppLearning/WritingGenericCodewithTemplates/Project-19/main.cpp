/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief FUNCTION TEMPLATES
 * @version 0.1
 * @date 2025-05-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include "funtemplate.hpp"
#include "spreadsheetCell.hpp"

using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------> 1
    cout << "//-----------> 1" << endl;

    int myInt = 3, intArray[] = {1, 2, 3, 4};
    const size_t sizeIntArray = std::size(intArray);
    size_t res;
    // res = Find(myInt, intArray, sizeIntArray); // calls Find<int> by deduction
    res = Find<int>(myInt, intArray, sizeIntArray); // calls Find<int> explicitly

    if (res != NOT_FOUND)
        cout << "myInt index : " << res << endl;
    else
        cout << "myInt Not found" << endl;

    //-----------> 2
    cout << "//-----------> 2" << endl;

    double myDouble = 5.6, doubleArray[] = {1.2, 3.4, 5.7, 7.5};
    const size_t sizeDoubleArray = std::size(doubleArray);
    // res = Find(myDouble, doubleArray, sizeDoubleArray);  // calls Find<double> by deduction
    res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // calls Find<double> explicitly

    if (res != NOT_FOUND)
        cout << "myDouble index : " << res << endl;
    else
        cout << "myDouble Not found" << endl;

    //-----------> 3
    cout << "//-----------> 3" << endl;

    // res = Find(myInt, doubleArray, sizeDoubleArray); // DOES NOT COMPILE! Arguments are different types.
    res = Find<double>(myInt, doubleArray, sizeDoubleArray); // calls Find<double> explicitly, even with myInt

    if (res != NOT_FOUND)
        cout << "myInt index : " << res << endl;
    else
        cout << "myInt Not found" << endl;

    //-----------> 4
    cout << "//-----------> 4" << endl;

    SpreadsheetCell cell1(10), cellArray[] = {SpreadsheetCell(4), SpreadsheetCell(10)};
    const size_t sizeCellArray = std::size(cellArray);
    //res = Find(cell1, cellArray, sizeCellArray); //by deduction
    res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray);//explicitly

    if (res != NOT_FOUND)
        cout << "SpreadsheetCell index : " << res << endl;
    else
        cout << "SpreadsheetCell Not found" << endl;

    //----------------> 5
    cout << "//-----------> 5" << endl;

    int myInt2 = 3, intArray2[] = {1, 2, 3, 4};
    res = Find(myInt2, intArray2);

    if (res != NOT_FOUND)
        cout << "myInt2 index : " << res << endl;
    else
        cout << "myInt2 Not found" << endl;

    return 0;
}