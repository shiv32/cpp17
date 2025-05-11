#include "AbstractClass.hpp"
#include "ConcreteClass2.hpp"
#include <iostream>

void ConcreteClass2::RequiredOperations1() const
{
    std::cout << "ConcreteClass2 says: Implemented Operation1\n";
}

void ConcreteClass2::RequiredOperation2() const
{
    std::cout << "ConcreteClass2 says: Implemented Operation2\n";
}

void ConcreteClass2::Hook1() const
{
    std::cout << "ConcreteClass2 says: Overridden Hook1\n";
}