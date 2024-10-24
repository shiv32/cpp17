/**
 * @file Context.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Context.hpp"

Context::Context(State *state) : state_(nullptr)
{
    this->TransitionTo(state);
}

Context::~Context()
{
    delete state_;
}

void Context::TransitionTo(State *state)
{
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
}

void Context::Request1()
{
    this->state_->Handle1();
}

void Context::Request2()
{
    this->state_->Handle2();
}