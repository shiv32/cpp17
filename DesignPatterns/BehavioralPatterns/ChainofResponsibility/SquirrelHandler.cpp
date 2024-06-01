#include "SquirrelHandler.hpp"

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