#pragma once

#include <unordered_map>
#include <initializer_list>

// class Flyweight;
// class SharedState;
#include "SharedState.hpp"
#include "Flyweight.hpp"

class FlyweightFactory
{

private:
    std::unordered_map<std::string, Flyweight> flyweights_;

    std::string GetKey(const SharedState &ss) const;

public:
    FlyweightFactory(std::initializer_list<SharedState> share_states);

    Flyweight GetFlyweight(const SharedState &shared_state);

    void ListFlyweights() const;
};