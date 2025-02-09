#pragma once

#include "AwithX.hpp"
#include "AwithY.hpp"
#include "AwithZ.hpp"

class AwithXYZ : public AwithX, public AwithY, public AwithZ
{
public:
    /*virtual*/
    void do_it();
};