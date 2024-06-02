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