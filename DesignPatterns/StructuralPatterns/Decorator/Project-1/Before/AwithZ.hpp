#pragma once

#include "A.hpp"

class AwithZ : public A
{
public:
    /*virtual*/
    void do_it();

protected:
    void do_Z();
};