#include "States/IdleState.hpp"
#include "Context.hpp"
#include "States/RunningState.hpp"

IdleState& IdleState::instance() {
    static IdleState inst;
    return inst;
}

void IdleState::handle(Context& ctx) {
    ctx.setState(&RunningState::instance());
}

std::string IdleState::name() const {
    return "Idle";
}