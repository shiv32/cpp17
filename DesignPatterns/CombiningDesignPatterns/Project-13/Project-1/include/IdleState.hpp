
#pragma once
#include "State.hpp"

class IdleState : public State {
public:
    void handle(Context& context, const std::string& command) override;
};
