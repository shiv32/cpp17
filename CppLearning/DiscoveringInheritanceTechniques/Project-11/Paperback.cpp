/**
 * @file Paperback.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Paperback.hpp"

std::string Paperback::getDescription() const
{
    return "Paperback " + Book::getDescription();
}