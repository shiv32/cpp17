#include "Button.hpp"
/**
 * @file Button.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-01-24
 *
 * @copyright Copyright (c) 2025
 *
 */

Button::Button(Callback c):m_Callback{c}
{
}

Button::~Button() {}

void Button::GenerateEvent() 
{
    m_Callback(nullptr);
}
