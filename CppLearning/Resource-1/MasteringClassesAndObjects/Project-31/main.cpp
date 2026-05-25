#include "Spreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--------------------------------------------------" << std::endl;

    // Spreadsheet s1(2, 2), s2(4, 3);
    auto s1 = std::make_shared<Spreadsheet>(2, 2);
    auto s2 = std::make_shared<Spreadsheet>(4, 3);

    std::cout << "s1 Width : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height : " << s1->getHeight() << std::endl;

    // std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    // std::cout << "s1 Height : " << s1.getHeight() << std::endl;

    s1 = s2;

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "s1 Width after assignment : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1->getHeight() << std::endl;

    // std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    // std::cout << "s1 Height : " << s1.getHeight() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}