#pragma once
#include "../State.hpp"

class PausedState : public State {
public:
    static PausedState& instance();
    void handle(Context& ctx) override;
    std::string name() const override;
};