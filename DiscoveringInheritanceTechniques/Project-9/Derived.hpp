/**
 * @file Derived.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Base.hpp"
#include "Something.hpp"

class Derived : public Base
{
public:
    Derived();
    virtual ~Derived();

private:
    Something mDataMember;
};