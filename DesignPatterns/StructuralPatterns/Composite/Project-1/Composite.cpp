#include "Composite.hpp"

void Composite::Add(Component *component)
{
    this->children_.push_back(component);
    component->SetParent(this);
}

void Composite::Remove(Component *component)
{
    children_.remove(component);
    component->SetParent(nullptr);
}

bool Composite::IsComposite() const
{
    return true;
}

std::string Composite::Operation() const
{
    std::string result;
    for (const Component *c : children_)
    {
        if (c == children_.back())
        {
            result += c->Operation();
        }
        else
        {
            result += c->Operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}
