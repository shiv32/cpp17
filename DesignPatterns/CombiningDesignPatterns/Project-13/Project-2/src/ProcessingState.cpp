
#include "ProcessingState.hpp"
#include "CompletedState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void ProcessingState::handle(Context& context, const std::string& command) {
    Logger::getInstance().log("ProcessingState handling: " + command);
    if (command == "complete") {
        context.setState(std::make_unique<CompletedState>());
    }
}

std::string ProcessingState::getName() const {
    return "ProcessingState";
}
