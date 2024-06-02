#include "SquirrelHandler.hpp"

void SquirrelHandler::HandlerName()
{
    std::cout << "SquirrelHandler called !" << std::endl;
}

std::string SquirrelHandler::Handle(std::string request)
{
    if (request == "Nut")
    {
        return "Squirrel: I'll eat the " + request + ".\n";
    }
    else
    {
        return AbstractHandler::Handle(request);
    }
}