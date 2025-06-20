
#include <iostream>
#include "myvartemplate.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int piInt = pi<int>;
    std::cout << "piInt : " << piInt << std::endl;

    float piFloat = pi<float>;
    std::cout << "piFloat : " << piFloat << std::endl;

    long double piLongDouble = pi<long double>;
    std::cout << "piLongDouble : " << piLongDouble << std::endl;

    return 0;
}