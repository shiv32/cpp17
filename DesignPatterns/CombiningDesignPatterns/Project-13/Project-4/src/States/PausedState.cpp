#include "States/PausedState.hpp"
#include "Context.hpp"

PausedState& PausedState::instance() {
    static PausedState inst;
    return inst;
}

void PausedState::handle(Context& ctx) {
    // Resume to Running
}

std::string PausedState::name() const {
    return "Paused";
}