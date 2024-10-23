#pragma once
#include "State.hpp"
#include "OFF.hpp"

class State;

class Machine
{
    class State *current;

public:
    Machine();
    void setCurrent(State *s);

    void on();
    void off();
};