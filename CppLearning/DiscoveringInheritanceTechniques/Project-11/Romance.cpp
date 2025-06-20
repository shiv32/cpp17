/**
 * @file Romance.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Romance.hpp"

std::string Romance::getDescription() const
{
    return "Romance " + Paperback::getDescription();
}

int Romance::getHeight() const
{
    return Paperback::getHeight() / 2;
}