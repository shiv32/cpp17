/*
   Implementing a Swap Function with Move Semantics
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

    Spreadsheet s(2, 3);

    std::cout << "s Width : " << s.getWidth() << std::endl;
    std::cout << "s Height : " << s.getHeight() << std::endl;
    std::cout << "s Sheetname : " << s.getSheetname() << std::endl;

    s = createObject();

    std::cout << "s Width after assignment : " << s.getWidth() << std::endl;
    std::cout << "s Height after assignment : " << s.getHeight() << std::endl;
    std::cout << "s Sheetname after assignment : " << s.getSheetname() << std::endl;

    Spreadsheet s2(std::move(s));

    std::cout << "s2 Width after assignment : " << s2.getWidth() << std::endl;
    std::cout << "s2 Height after assignment : " << s2.getHeight() << std::endl;
    std::cout << "s2 Sheetname after assignment : " << s2.getSheetname() << std::endl;

    Spreadsheet s3(5, 6);

    std::cout << "s3 Width : " << s3.getWidth() << std::endl;
    std::cout << "s3 Height : " << s3.getHeight() << std::endl;
    std::cout << "s3 Sheetname : " << s3.getSheetname() << std::endl;

    s3 = std::move(s2);

    std::cout << "s3 Width after assignment : " << s3.getWidth() << std::endl;
    std::cout << "s3 Height after assignment : " << s3.getHeight() << std::endl;
    std::cout << "s3 Sheetname after assignment : " << s3.getSheetname() << std::endl;

    return 0;
}