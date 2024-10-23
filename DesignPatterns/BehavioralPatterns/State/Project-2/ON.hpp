#pragma once
#include "State.hpp"
#include "Machine.hpp"

class ON : public State
{
public:
    ON();
    ~ON();
    void off(Machine *m);
};
