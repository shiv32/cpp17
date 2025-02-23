/**
 * @file Y.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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