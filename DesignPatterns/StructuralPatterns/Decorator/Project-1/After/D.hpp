/**
 * @file D.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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