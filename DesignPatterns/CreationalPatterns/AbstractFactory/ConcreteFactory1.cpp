#include "ConcreteFactory1.hpp"

AbstractProductA *ConcreteFactory1::CreateProductA() const
{
    return new ConcreteProductA1();
}

AbstractProductB *ConcreteFactory1::CreateProductB() const
{
    return new ConcreteProductB1();
}