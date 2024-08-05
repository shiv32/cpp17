/**
 * @file MonkeyHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MonkeyHandler.hpp"

void MonkeyHandler::HandlerName()
{
    std::cout << "MonkeyHandler called !" << std::endl;
}

std::string MonkeyHandler::Handle(std::string request)
{
    if (request == "Banana")
    {
        return "Monkey: I'll eat the " + request + ".\n";
    }
    else
    {
        return AbstractHandler::Handle(request);
    }
}