#include <iostream>
#include "Machine.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    void (Machine::*ptrs[])() = {&Machine::off, &Machine::on};

    Machine fsm;

    int num;

    while (1)
    {
        std::cout << "Enter 0/1: ";
        std::cin >> num;
        (fsm.*ptrs[num])();
    }

    return 0;
}
