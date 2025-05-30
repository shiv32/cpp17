#include "AbstractClass.hpp"
#include <iostream>

void AbstractClass::TemplateMethod() const
{
    this->BaseOperation1();
    this->RequiredOperations1();
    this->BaseOperation2();
    this->Hook1();
    this->RequiredOperation2();
    this->BaseOperation3();
    this->Hook2();
}

void AbstractClass::BaseOperation1() const
{
    std::cout << "AbstractClass says: I am doing the bulk of the work\n";
}

void AbstractClass::BaseOperation2() const
{
    std::cout << "AbstractClass says: But I let subclasses override some operations\n";
}

void AbstractClass::BaseOperation3() const
{
    std::cout << "AbstractClass says: But I am doing the bulk of the work anyway\n";
}

void AbstractClass::Hook1() const {}
void AbstractClass::Hook2() const {}
