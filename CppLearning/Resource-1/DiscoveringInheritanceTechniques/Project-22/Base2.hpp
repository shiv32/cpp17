/**
 * @file Base2.hpp
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

class Base2
{
public:
    virtual ~Base2() = default;
    Base2() = default;
    Base2(std::string_view str);
    Base2(float f);
};