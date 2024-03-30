/*
VARIABLE TEMPLATES

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "myvartemplate.hpp"

int main()
{
    int piInt = pi<int>;

    std::cout << "piInt : " << piInt << std::endl;

    float piFloat = pi<float>;

    std::cout << "piFloat : " << piFloat << std::endl;

    long double piLongDouble = pi<long double>;

    std::cout << "piLongDouble : " << piLongDouble << std::endl;

    return 0;
}