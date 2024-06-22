#include "ConcreteProductB1.hpp"

std::string ConcreteProductB1::UsefulFunctionB() const
{
    return "The result of the product B1.";
}

std::string ConcreteProductB1::AnotherUsefulFunctionB(const AbstractProductA &collaborator) const
{
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
}