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