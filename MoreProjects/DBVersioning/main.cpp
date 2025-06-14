#include "db_migrator.hpp"
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    DBMigrator migrator("test.db", "../migrations");

    std::cout << "1. Apply migrations\n2. Show status\n3. Reset\nChoice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        migrator.applyMigrations();
        break;
    case 2:
        migrator.showStatus();
        break;
    case 3:
        migrator.reset();
        break;
    default:
        std::cout << "Invalid\n";
    }

    return 0;
}
