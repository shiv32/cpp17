/**
 * @file OFF.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "OFF.hpp"

OFF::OFF()
{
    std::cout << "   OFF-ctor ";
};

OFF::~OFF()
{
    std::cout << "   dtor-OFF\n";
};

void OFF::on(Machine *m)
{
    std::cout << "   going from OFF to ON";
    m->setCurrent(new ON());
    delete this;
}