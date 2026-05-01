/**
 * @file Base.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <string>

class Base
{
public:
    virtual ~Base() = default;
    Base() = default;
    Base(std::string_view str);
    Base(float f);
};