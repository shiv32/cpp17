#include "D.hpp"

D::D(I *inner)
{
    m_wrappee = inner;
}

D::~D()
{
    delete m_wrappee;
}

void D::do_it()
{
    m_wrappee->do_it();
}
