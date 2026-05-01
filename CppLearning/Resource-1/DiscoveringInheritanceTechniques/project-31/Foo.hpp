#pragma once

#include "Loggable.hpp"

class Foo : public Loggable
{
public:
    std::string getLogMessage() const override;
};