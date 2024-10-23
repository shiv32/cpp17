#pragma once

#include "State.hpp"

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class ConcreteStateA : public State
{
public:
    void Handle1() override;
    void Handle2() override;
};