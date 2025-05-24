
#include "CompletedState.hpp"
#include "IdleState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void CompletedState::handle(Context& context, const std::string& command) {
    Logger::getInstance().log("CompletedState handling: " + command);
    if (command == "reset") {
        context.setState(std::make_unique<IdleState>());
    }
}

std::string CompletedState::getName() const {
    return "CompletedState";
}
