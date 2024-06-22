#include "ConcreteProductB2.hpp"

std::string ConcreteProductB2::UsefulFunctionB() const
{
    return "The result of the product B2.";
}

std::string ConcreteProductB2::AnotherUsefulFunctionB(const AbstractProductA &collaborator) const
{
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
}