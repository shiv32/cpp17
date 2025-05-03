#include "Creator.hpp"

std::string Creator::SomeOperation() const
{
    // Call the factory method to create a Product object.
    Product *product = this->FactoryMethod();

    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    
    delete product;
    return result;
}