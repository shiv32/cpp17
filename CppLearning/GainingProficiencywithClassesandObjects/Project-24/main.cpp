#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //-------------------------------- case 1 ------------------------------------------
    /*
   SpreadsheetCell myCell(5);

   if (myCell.getValue() == 5)
   {
       SpreadsheetCell anotherCell(6);
   } // anotherCell is destroyed as this block ends.

   std::cout << "myCell: " << myCell.getValue() << std::endl;
    */

    //----------------------------------- case 2 ------------------------------------
    /*
   {
       SpreadsheetCell myCell2(4);
       SpreadsheetCell anotherCell2(5); // myCell2 constructed before anotherCell2
   } // anotherCell2 destroyed before myCell2
     */

    //------------------------------------ case 3 --------------------------------------

    SpreadsheetCell *cellPtr1 = new SpreadsheetCell(5);
    SpreadsheetCell *cellPtr2 = new SpreadsheetCell(6);

    std::cout << "cellPtr1: " << cellPtr1->getValue() << std::endl;

    delete cellPtr1; // Destroys cellPtr1
    cellPtr1 = nullptr;

    return 0;
} // cellPtr2 is NOT destroyed because delete was not called on it.(Solution: Use smart pointers)