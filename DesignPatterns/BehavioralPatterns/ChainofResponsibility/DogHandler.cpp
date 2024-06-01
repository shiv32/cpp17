#include "DogHandler.hpp"

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