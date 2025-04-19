#include "Product1.hpp"
#include <iostream>

void Product1::ListParts() const 
{
    std::cout << "Product parts: ";
    for (size_t i = 0; i < parts_.size(); i++)
    {
        if (parts_[i] == parts_.back())
        {
            std::cout << parts_[i];
        }
        else
        {
            std::cout << parts_[i] << ", ";
        }
    }
    std::cout << "\n\n";
}
