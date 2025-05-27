
#include "IdleState.hpp"
#include "ProcessingState.hpp"
#include "Context.hpp"
#include "Logger.hpp"

void IdleState::handle(Context &context, const std::string &command)
{
    Logger::getInstance().log("IdleState received command: " + command);
    
    if (command == "start")
    {
        Logger::getInstance().log("Switching to ProcessingState");
        context.setState(std::make_unique<ProcessingState>());
    }
}
