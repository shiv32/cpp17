#pragma once

#include "I.hpp"

class A : public I
{
public:
    ~A();

    /*virtual*/
    void do_it();
};