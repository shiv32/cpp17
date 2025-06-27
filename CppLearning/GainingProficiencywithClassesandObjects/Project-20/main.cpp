#include <iostream>

void printString(std::string inString)
{
    std::cout << inString << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string name = "heading one shiv";

    printString(name); // Copies name

    return 0;
}