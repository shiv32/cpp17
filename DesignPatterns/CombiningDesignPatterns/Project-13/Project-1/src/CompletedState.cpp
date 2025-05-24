
#include "CompletedState.hpp"
#include "IdleState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void CompletedState::handle(Context& context, const std::string& command) {
    Logger::getInstance().log("CompletedState received command: " + command);
    if (command == "reset") {
        Logger::getInstance().log("Switching to IdleState");
        context.setState(std::make_unique<IdleState>());
    }
}
