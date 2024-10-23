#include "State.hpp"

void State::on(Machine *m)
{
    std::cout << "   already ON\n";
}

void State::off(Machine *m)
{
    std::cout << "   already OFF\n";
}