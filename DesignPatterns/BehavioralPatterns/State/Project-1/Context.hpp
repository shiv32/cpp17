/**
 * @file Context.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "State.hpp"

/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */

class State;

class Context
{
    /**
     * @var State A reference to the current state of the Context.
     */
private:
    State *state_;

public:
    Context(State *state);
    ~Context();

    /**
     * The Context allows changing the State object at runtime.
     */
    void TransitionTo(State *state);

    /**
     * The Context delegates part of its behavior to the current State object.
     */
    void Request1();
    void Request2();
};