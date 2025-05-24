#pragma once
#include "../State.hpp"

class IdleState : public State {
public:
    static IdleState& instance();
    void handle(Context& ctx) override;
    std::string name() const override;
};