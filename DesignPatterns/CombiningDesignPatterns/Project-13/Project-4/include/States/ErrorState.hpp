#pragma once
#include "../State.hpp"

class ErrorState : public State {
public:
    static ErrorState& instance();
    void handle(Context& ctx) override;
    std::string name() const override;
};