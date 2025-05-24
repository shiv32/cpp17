#include "Command.hpp"
#include "States/RunningState.hpp"
#include "States/IdleState.hpp"
#include "States/PausedState.hpp"
#include "States/CompletedState.hpp"
#include "States/ErrorState.hpp"

void StartCommand::execute(Context& ctx) {
    ctx.setState(&RunningState::instance());
}

void PauseCommand::execute(Context& ctx) {
    ctx.setState(&PausedState::instance());
}

void ResumeCommand::execute(Context& ctx) {
    ctx.setState(&RunningState::instance());
}

void CompleteCommand::execute(Context& ctx) {
    ctx.setState(&CompletedState::instance());
}

void ErrorCommand::execute(Context& ctx) {
    ctx.setState(&ErrorState::instance());
}

void ResetCommand::execute(Context& ctx) {
    ctx.setState(&IdleState::instance());
}