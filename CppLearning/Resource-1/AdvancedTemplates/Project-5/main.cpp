/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
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

    [[maybe_unused]] size_t res = NOT_FOUND;

    int myInt = 3, intArray[] = {1, 2, 3, 4};
    size_t sizeArray = std::size(intArray);

    res = Find(myInt, intArray, sizeArray);      // calls Find<int> by deduction
    res = Find<int>(myInt, intArray, sizeArray); // calls Find<int> explicitly

    //---------------------------
    // double myDouble = 5.6, doubleArray[] = {1.2, 3.4, 5.7, 7.5};
    // sizeArray = std::size(doubleArray);

    // res = Find(myDouble, doubleArray, sizeArray);         // calls Find<double> by deduction
    // res = Find<double>(myDouble, doubleArray, sizeArray); // calls Find<double> explicitly

    //----------------------------
    // const char *word = "two";
    // const char *words[] = {"one", "two", "three", "four"};
    // sizeArray = std::size(words);

    // res = Find<const char *>(word, words, sizeArray); // calls template specialization for const char*s
    // res = Find(word, words, sizeArray);               // calls overloaded Find for const char*s

    //----------------------------
    // int *intPointer = &myInt, *pointerArray[] = {&myInt, &myInt};
    // sizeArray = std::size(pointerArray);

    // res = Find(intPointer, pointerArray, sizeArray); // calls the overloaded Find for pointers

    //----------------------------------
    // SpreadsheetCell cell1(10), cellArray[] = {SpreadsheetCell(4),
    //                                           SpreadsheetCell(10)};
    // sizeArray = std::size(cellArray);

    // res = Find(cell1, cellArray, sizeArray);                  // calls Find<SpreadsheetCell> by deduction
    // res = Find<SpreadsheetCell>(cell1, cellArray, sizeArray); // calls Find<SpreadsheetCell> explicitly

    //---------------------------------
    // SpreadsheetCell *cellPointer = &cell1;
    // SpreadsheetCell *cellPointerArray[] = {&cell1, &cell1};
    // sizeArray = std::size(cellPointerArray);

    // res = Find(cellPointer, cellPointerArray, sizeArray);// Calls the overloaded Find for pointers

    return 0;
}