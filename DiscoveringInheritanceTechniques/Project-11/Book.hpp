/**
 * @file Book.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>

class Book
{
public:
    virtual ~Book() = default;
    virtual std::string getDescription() const;
    virtual int getHeight() const;
};