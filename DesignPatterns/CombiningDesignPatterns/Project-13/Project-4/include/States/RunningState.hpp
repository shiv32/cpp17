#pragma once
#include "../State.hpp"

class RunningState : public State {
public:
    static RunningState& instance();
    void handle(Context& ctx) override;
    std::string name() const override;
};