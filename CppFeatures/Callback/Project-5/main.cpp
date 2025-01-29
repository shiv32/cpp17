/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Function Objects
 *
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

struct PrettyPrint
{
    int count{};
    
    void operator()(const char *p) //function call operator
    {
        std::cout << "****** " << p << " ********" << std::endl;
        ++count;
    }
};

void PP(const char *p)
{
   static int i{};
   ++i;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    PrettyPrint pt{};

    pt("Hello Shiv"); // call function object
    pt("Hello Shiv"); // call function object
    pt("Hello Shiv"); // call function object

    PrettyPrint pt2{};
    pt2("Hello Shiv"); // call function object

    std::cout << "Count : " << pt.count << std::endl;

    PP("Using function");

    return 0;
}