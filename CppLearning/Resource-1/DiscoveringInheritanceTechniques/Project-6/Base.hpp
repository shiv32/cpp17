/**
 * @file Base.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>

class Base
{
public:
    Base();

    ~Base();
    //virtual ~Base();

    //virtual ~Base() = default;
    virtual void someMethod() final;
};
