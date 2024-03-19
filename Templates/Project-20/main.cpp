/*
FUNCTION TEMPLATES

std::optional<size_t> version

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "funtemplate.hpp"
#include "spreadsheetCell.hpp"

using namespace std;

int main()
{
    //------------> 1
    cout << "//-----------> 1" << endl;
    int myInt = 3, intArray[] = {1, 2, 3, 4};

    const size_t sizeIntArray = std::size(intArray);

     std::optional<size_t> res;

    res = Find(myInt, intArray, sizeIntArray); // calls Find<int> by deduction

    res = Find<int>(myInt, intArray, sizeIntArray); // calls Find<int> explicitly

    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    //-----------> 2
    cout << "//-----------> 2" << endl;
    double myDouble = 5.6, doubleArray[] = {1.2, 3.4, 5.7, 7.5};

    const size_t sizeDoubleArray = std::size(doubleArray);

    // calls Find<double> by deduction
    res = Find(myDouble, doubleArray, sizeDoubleArray);

    // calls Find<double> explicitly
    res = Find<double>(myDouble, doubleArray, sizeDoubleArray);

    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    //-----------> 3
    cout << "//-----------> 3" << endl;
    // res = Find(myInt, doubleArray, sizeDoubleArray); // DOES NOT COMPILE! Arguments are different types.

    // calls Find<double> explicitly, even with myInt
    res = Find<double>(myInt, doubleArray, sizeDoubleArray);

    //-----------> 4
    cout << "//-----------> 4" << endl;
    SpreadsheetCell cell1(10), cellArray[] = {SpreadsheetCell(4), SpreadsheetCell(10)};

    const size_t sizeCellArray = std::size(cellArray);

    res = Find(cell1, cellArray, sizeCellArray);

    res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray);

    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    //----------------> 5
     cout << "//-----------> 5" << endl;
    int myInt2 = 3, intArray2[] = {1, 2, 3, 4};
    res = Find(myInt2, intArray2);
    
    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    return 0;
}