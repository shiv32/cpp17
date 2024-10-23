#include "Machine.hpp"

Machine::Machine()
{
    current = new OFF();
    std::cout << '\n';
}

void Machine::setCurrent(State *s) { current = s; }

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}
