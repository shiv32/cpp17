/**
 * @file Button.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

using Callback = void(*)(void *);

class Button
{
    Callback m_Callback;

public:
    Button(Callback c);
    ~Button();
    void GenerateEvent();
};

