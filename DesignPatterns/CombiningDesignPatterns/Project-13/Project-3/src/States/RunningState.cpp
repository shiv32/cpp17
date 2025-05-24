#include "States/RunningState.hpp"
#include "Context.hpp"
#include "States/IdleState.hpp"

RunningState& RunningState::instance() {
    static RunningState inst;
    return inst;
}

void RunningState::handle(Context& ctx) {
    ctx.setState(&IdleState::instance());
}

std::string RunningState::name() const {
    return "Running";
}