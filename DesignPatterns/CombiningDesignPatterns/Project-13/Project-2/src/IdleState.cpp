
#include "IdleState.hpp"
#include "ProcessingState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void IdleState::handle(Context& context, const std::string& command) {
    Logger::getInstance().log("IdleState handling: " + command);
    if (command == "start") {
        context.setState(std::make_unique<ProcessingState>());
    }
}

std::string IdleState::getName() const {
    return "IdleState";
}
