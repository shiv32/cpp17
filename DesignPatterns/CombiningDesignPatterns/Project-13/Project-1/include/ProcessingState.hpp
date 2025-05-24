
#pragma once
#include "State.hpp"

class ProcessingState : public State {
public:
    void handle(Context& context, const std::string& command) override;
};
