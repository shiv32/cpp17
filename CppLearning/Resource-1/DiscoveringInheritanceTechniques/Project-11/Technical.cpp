#include "Technical.hpp"

std::string Technical::getDescription() const
{
    return "Technical " + Book::getDescription();
}