/**
 * @file Technical.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "Book.hpp"

class Technical : public Book
{
public:
    virtual std::string getDescription() const override;
};