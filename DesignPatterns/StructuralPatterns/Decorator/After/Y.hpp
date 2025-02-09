#pragma once

#include "D.hpp"

class Y : public D
{
public:
    Y(I *core);
    ~Y();

    /*virtual*/
    void do_it();
};