#pragma once

#include <algorithm> // for std::reverse
#include "Target.hpp"
#include "Adaptee.hpp"

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target
{
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override;
};