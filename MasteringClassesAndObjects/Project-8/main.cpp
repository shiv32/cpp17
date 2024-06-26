/*
   Testing the Spreadsheet Move Operations
*/

#include <iostream>
#include "Spreadsheet.hpp"
#include <vector>

Spreadsheet createObject()
{
    return Spreadsheet(3, 2);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<Spreadsheet> vec;

    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Iteration " << i << std::endl;
        vec.push_back(Spreadsheet(100, 100));
        std::cout << std::endl;
    }

    Spreadsheet s(2, 3);

    std::cout << "s Width : " << s.getWidth() << std::endl;
    std::cout << "s Height : " << s.getHeight() << std::endl;
    std::cout << "s Sheetname : " << s.getSheetname() << std::endl;

    s = createObject();

    std::cout << "s Width after assignment : " << s.getWidth() << std::endl;
    std::cout << "s Height after assignment : " << s.getHeight() << std::endl;
    std::cout << "s Sheetname after assignment : " << s.getSheetname() << std::endl;

    Spreadsheet s2(5, 6);

    std::cout << "s2 Width : " << s2.getWidth() << std::endl;
    std::cout << "s2 Height : " << s2.getHeight() << std::endl;
    std::cout << "s2 Sheetname : " << s2.getSheetname() << std::endl;

    s2 = s;

    std::cout << "s2 Width after assignment : " << s2.getWidth() << std::endl;
    std::cout << "s2 Height after assignment : " << s2.getHeight() << std::endl;
    std::cout << "s2 Sheetname after assignment : " << s2.getSheetname() << std::endl;

    return 0;
}