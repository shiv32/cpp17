/*
static instance of Test class call Test class constructor in compile time.
g++ *.cpp -o test
*/

#include <iostream>

int main()
{
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}