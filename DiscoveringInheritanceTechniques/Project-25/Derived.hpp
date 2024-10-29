#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
    using Base::overload;
    virtual void overload() override;
};