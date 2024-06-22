#include "ConcreteCreator2.hpp"

Product *ConcreteCreator2::FactoryMethod() const
{
    return new ConcreteProduct2();
}