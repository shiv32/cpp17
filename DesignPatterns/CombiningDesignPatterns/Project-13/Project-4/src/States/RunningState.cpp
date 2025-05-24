#include "States/RunningState.hpp"
#include "Context.hpp"

RunningState& RunningState::instance() {
    static RunningState inst;
    return inst;
}

void RunningState::handle(Context& ctx) {
    // Possibly transition to Completed/Error
}

std::string RunningState::name() const {
    return "Running";
}
