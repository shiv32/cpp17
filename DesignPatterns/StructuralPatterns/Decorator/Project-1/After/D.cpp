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
#include <iostream>

D::D(I *inner):m_wrappee{inner}
{
    //m_wrappee = inner;
}

D::~D()
{
    //std::cout <<__PRETTY_FUNCTION__<< '\n';
    delete m_wrappee;
}

void D::do_it()
{
    m_wrappee->do_it();
}
