#include "ConcreteCreator1.hpp"

Product *ConcreteCreator1::FactoryMethod() const
{
    return new ConcreteProduct1();
}