/*
        The assert macro in C++ is used to verify assumptions made by the program 
        and to catch bugs during the development phase.
*/

#include <iostream>
#include <cassert>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int x = 5;

    // assert(x == 5); // This will pass

    assert(x == 0); // This will fail and terminate the program

    return 0;
}
