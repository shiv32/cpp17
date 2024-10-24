/**
 * @file State.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "State.hpp"

State::~State()
{
}

void State::set_context(Context *context)
{
    this->context_ = context;
}