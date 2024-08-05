/**
 * @file SquirrelHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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