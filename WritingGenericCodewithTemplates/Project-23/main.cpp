#include <iostream>
#include "grid.hpp"

using gridInt = Grid<int>;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    gridInt myInt(8, 8);
    gridInt myInt2(8, 8);
    gridInt myInt3(8, 8);

    myInt.at(0, 0) = 2;
    myInt2.at(0, 0) = 3;

    myInt3 = myInt + myInt2;

    std::cout << "myInt3 (0,0) : " << myInt3.at(0, 0).value_or(0) << std::endl;

    return 0;
}