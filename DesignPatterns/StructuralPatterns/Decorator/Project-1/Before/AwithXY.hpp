/**
 * @file AwithXY.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "AwithX.hpp"
#include "AwithY.hpp"

class AwithXY : public AwithX, public AwithY
{
public:
    /*virtual*/
    void do_it();
};