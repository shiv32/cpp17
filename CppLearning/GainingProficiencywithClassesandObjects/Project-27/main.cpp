#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    SpreadsheetCell myCell2(5);
    std::string s1;
    s1 = myCell2.getString(); // invokes the copy constructor and the assignment operator (for two different objects).
                              // Compilers are free and sometimes required to implement Return Value Optimization (RVO) (copy elision)
                              // to optimize away costly copy constructions when returning values.

    SpreadsheetCell myCell3(5);
    std::string s2 = myCell3.getString(); // s2 gets its copy constructor called, not its assignment operator.
                                          // With move semantics, the compiler can use a move constructor instead of a copy constructor to
                                          // return the string from getString(). This is more efficient.

    return 0;
}