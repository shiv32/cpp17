
#include "ProcessingState.hpp"
#include "CompletedState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void ProcessingState::handle(Context& context, const std::string& command) {
    Logger::getInstance().log("ProcessingState received command: " + command);
    if (command == "complete") {
        Logger::getInstance().log("Switching to CompletedState");
        context.setState(std::make_unique<CompletedState>());
    }
}
