#include <iostream>
#include "Flyweight.hpp"
// #include "SharedState.hpp"
// #include "UniqueState.hpp"

Flyweight::Flyweight(const SharedState *shared_state)
    : shared_state_(new SharedState(*shared_state))
{
}

Flyweight::Flyweight(const Flyweight &other)
    : shared_state_(new SharedState(*other.shared_state_))
{
}

Flyweight::~Flyweight()
{
    delete shared_state_;
}

SharedState *Flyweight::shared_state() const
{
    return shared_state_;
}

void Flyweight::Operation(const UniqueState &unique_state) const
{
    std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
}
