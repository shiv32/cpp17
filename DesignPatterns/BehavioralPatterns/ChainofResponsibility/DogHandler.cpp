/**
 * @file DogHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "DogHandler.hpp"

void DogHandler::HandlerName()
{
    std::cout<<"DogHandler called !"<<std::endl;
}

std::string DogHandler::Handle(std::string request)
{
    if (request == "MeatBall")
    {
        return "Dog: I'll eat the " + request + ".\n";
    }
    else
    {
        return AbstractHandler::Handle(request);
    }
}