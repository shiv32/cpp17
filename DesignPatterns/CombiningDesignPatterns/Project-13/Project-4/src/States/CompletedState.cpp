#include "States/CompletedState.hpp"
#include "Context.hpp"

CompletedState& CompletedState::instance() {
    static CompletedState inst;
    return inst;
}

void CompletedState::handle(Context& ctx) {
    // Reset to Idle
}

std::string CompletedState::name() const {
    return "Completed";
}