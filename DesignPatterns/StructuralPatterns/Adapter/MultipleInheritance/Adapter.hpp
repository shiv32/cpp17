#pragma once

#include <algorithm> // for std::reverse
#include "Target.hpp"
#include "Adaptee.hpp"

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
class Adapter : public Target, public Adaptee
{
public:
    Adapter();
    std::string Request() const override;
};
