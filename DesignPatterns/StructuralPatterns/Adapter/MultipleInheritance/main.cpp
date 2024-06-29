/*
Adapter using Multiple inheritance
g++ *.cpp -o test
*/

#include <iostream>
#include "Adapter.hpp"

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target *target)
{
    std::cout << target->Request();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "Client: I can work just fine with the Target objects:\n";

    Target *target = new Target;
    ClientCode(target);

    std::cout << "\n\n";

    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";

    Adapter *adapter = new Adapter;
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
