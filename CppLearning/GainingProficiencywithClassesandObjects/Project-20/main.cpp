/*
When the Copy Constructor Is Called

C++ string is actually a class, not a built-in type.

Whenever you pass an object to a function or method, the compiler calls the copy constructor of the new object to initialize it.

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>

//the string copy constructor is executed for the inString object in printString() with name as its parameter.
//When the printString() method finishes, inString is destroyed. Because it was only a copy of name, name remains intact.
void printString(std::string inString)
{
    std::cout << inString << std::endl;
}

int main()
{
    std::string name = "heading one shiv";
    printString(name); // Copies name

    return 0;
}