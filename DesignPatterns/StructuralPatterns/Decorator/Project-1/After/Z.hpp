#pragma once

#include "D.hpp"

class Z : public D
{
public:
    Z(I *core);

    ~Z();

    /*virtual*/
    void do_it();
};