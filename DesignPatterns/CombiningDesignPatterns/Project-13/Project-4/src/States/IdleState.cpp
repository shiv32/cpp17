#include "States/IdleState.hpp"
#include "Context.hpp"

IdleState& IdleState::instance() {
    static IdleState inst;
    return inst;
}

void IdleState::handle(Context& ctx) {
    // Possibly set to Running
}

std::string IdleState::name() const {
    return "Idle";
}