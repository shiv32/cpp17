/*
Constructor Initializers part 3

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "MyClass.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    MyClass instance(1.2);

    return 0;
}