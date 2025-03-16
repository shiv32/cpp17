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
