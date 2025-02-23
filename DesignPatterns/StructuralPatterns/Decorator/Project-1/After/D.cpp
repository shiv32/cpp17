/**
 * @file D.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "D.hpp"

D::D(I *inner):m_wrappee{inner}
{
    //m_wrappee = inner;
}

D::~D()
{
    delete m_wrappee;
}

void D::do_it()
{
    m_wrappee->do_it();
}
