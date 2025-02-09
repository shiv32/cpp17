#pragma once

#include "I.hpp"

class D : public I
{
public:
    D(I *inner);

    ~D();

    /*virtual*/
    void do_it();

private:
    I *m_wrappee;
};