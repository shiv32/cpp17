#pragma once

class Base
{
public:
    virtual ~Base() = default;
    virtual void overload();
    virtual void overload(int i);
};