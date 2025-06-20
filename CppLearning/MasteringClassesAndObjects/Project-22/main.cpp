/*
        NESTED CLASSES Part-2
                Fully defining the nested Cell class directly inside the Spreadsheet class makes the definition of the
                Spreadsheet class a bit bloated. 
                
                Alleviate this by only including a forward declaration for Cell in the Spreadsheet class,
                and then defining the Cell class separately.
                
                If you declare a private or protected nested class, you can only use it inside the outer class. 
                
                A nested class has access to all protected and private members of the outer class. 
                The outer class on the other hand can only access public members of the nested class.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{
        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_shared<Spreadsheet>(5, 6);
        auto sc1 = std::make_shared<Spreadsheet::Cell>(5.66);

        sheet1->setCellAt(1, 1, sc1);

        std::cout << "sheet1->getCellAt(1, 1) : " << sheet1->getCellAt(1, 1) << std::endl;

         auto &cell1 = sheet1->getCellAt(1, 1);

        std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
        std::cout << "Cell2 value at (1,1) string : " << cell1->getString() << std::endl;

        return 0;
}