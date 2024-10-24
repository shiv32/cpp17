/**
 * @file ON.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ON.hpp"

ON::ON()
{
    std::cout << "   ON-ctor ";
};

ON::~ON()
{
    std::cout << "   dtor-ON\n";
};

void ON::off(Machine *m)
{
    std::cout << "   going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}