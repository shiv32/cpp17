#include "Product1.hpp"
#include <iostream>

void Product1::ListParts() const
{
    std::cout << "Product parts: ";

    // for (size_t i = 0; i < parts_.size(); i++)
    // {
    //     if (parts_[i] == parts_.back()) //last part
    //     {
    //         std::cout << parts_[i];
    //     }
    //     else
    //     {
    //         std::cout << parts_[i] << ", ";
    //     }
    // }

    size_t count = 0;
    
    for (const auto &part : parts_)
    {
        if (++count == parts_.size()) //last part
        {
            std::cout << part;
        }
        else
        {
            std::cout << part << ", ";
        }
    }

    std::cout << "\n\n";
}
