/**
 * @file Prototype.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Prototype.hpp"

Prototype::Prototype(std::string prototype_name) : prototype_name_(prototype_name)
{
}

void Prototype::Method(float prototype_field)
{
    this->prototype_field_ = prototype_field;
    std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
}
