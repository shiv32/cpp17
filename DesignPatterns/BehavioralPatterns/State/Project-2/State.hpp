#pragma once
#include <iostream>

class Machine;

class State
{
public:
    virtual void on(Machine *m);
    virtual void off(Machine *m);
};