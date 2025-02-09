#pragma once

#include "D.hpp"

class X : public D
{
public:
    X(I *core);

    ~X();

    /*virtual*/
    void do_it();
};