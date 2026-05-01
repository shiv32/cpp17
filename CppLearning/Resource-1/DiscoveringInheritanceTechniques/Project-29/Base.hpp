#pragma once

class Base
{
public:
    virtual ~Base() = default;
    Base();
    Base(const Base &src);
    Base& operator=(const Base& rhs);
};