#pragma once

#include "AwithX.hpp"
#include "AwithY.hpp"

class AwithXY : public AwithX, public AwithY
{
public:
    /*virtual*/
    void do_it();
};