#include <iostream>
#include "SpreadsheetCell.hpp"

using namespace std;

void test1()
{
    SpreadsheetCell cell(1.23);

    double d1 = cell; // DOES NOT COMPILE!, Works as expected after overload double()
    // double d1 = (double)cell; // STILL DOES NOT COMPILE!, Works as expected after overload double()

    cout << "d1: " << d1 << endl;

    string str = cell;
    cout << "str: " << str << endl;
}

void test2()
{
    SpreadsheetCell cell(1.23);

    // double d2 = cell + 3.3; // DOES NOT COMPILE IF YOU DEFINE operator double()

    // cout << "d2: " << d2 << endl;
}

void test3()
{
    SpreadsheetCell cell = 6.6;

    string str = cell;
    double d1 = static_cast<double>(cell);
    double d2 = static_cast<double>(cell + 3.3);
    // double d2 = static_cast<double>(cell) + 3.3;
    double d3 = static_cast<double>(3.3 + cell);

    cout << "str: " << str << endl;
    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d3: " << d3 << endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // test1();
    // test2();
    test3();

    return 0;
}