/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Spreadsheet.hpp"
#include "AbstractSpreadsheet.hpp"
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--------------------------------------------------" << std::endl;

    std::shared_ptr<AbstractSpreadsheet> s1 = std::make_shared<Spreadsheet>(2, 2);
    std::shared_ptr<AbstractSpreadsheet> s2 = std::make_shared<Spreadsheet>(4, 3);

    std::cout << "s1 Width : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height : " << s1->getHeight() << std::endl;

    s1 = s2;

    std::cout << "s1 Width after assignment : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1->getHeight() << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}