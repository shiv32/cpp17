#pragma once
#include "../State.hpp"

class CompletedState : public State {
public:
    static CompletedState& instance();
    void handle(Context& ctx) override;
    std::string name() const override;
};