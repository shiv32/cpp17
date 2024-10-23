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