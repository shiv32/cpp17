/**
 * @file Component.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Component.hpp"

Component::~Component()
{
}

void Component::SetParent(Component *parent)
{
    this->parent_ = parent;
}

Component *Component::GetParent() const
{
    return nullptr;
}

void Component::Add(Component *component)
{
}

void Component::Remove(Component *component)
{
}

bool Component::IsComposite() const
{
    return false;
}
