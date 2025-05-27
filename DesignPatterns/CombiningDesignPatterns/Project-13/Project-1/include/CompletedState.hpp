
#pragma once
#include "State.hpp"

class CompletedState : public State
{
public:
    void handle(Context &context, const std::string &command) override;
};
