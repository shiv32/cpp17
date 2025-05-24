#include "Command.hpp"
#include "States/RunningState.hpp"
#include "States/IdleState.hpp"

void StartCommand::execute(Context& ctx) {
    ctx.setState(&RunningState::instance());
}

void PauseCommand::execute(Context& ctx) {
    ctx.setState(&IdleState::instance());
}
