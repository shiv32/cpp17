#include "AbstractClass.hpp"
#include "ConcreteClass1.hpp"
#include <iostream>

void ConcreteClass1::RequiredOperations1() const
{
    std::cout << "ConcreteClass1 says: Implemented Operation1\n";
}

void ConcreteClass1::RequiredOperation2() const
{
    std::cout << "ConcreteClass1 says: Implemented Operation2\n";
}