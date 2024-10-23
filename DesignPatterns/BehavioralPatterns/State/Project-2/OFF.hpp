#pragma once
#include "State.hpp"
#include "ON.hpp"
#include "Machine.hpp"

class Machine;

class OFF : public State
{
public:
    OFF();
    ~OFF();
    void on(Machine *m);
};