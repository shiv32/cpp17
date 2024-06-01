#include "AbstractHandler.hpp"

AbstractHandler::AbstractHandler() : next_handler_(nullptr)
{
}

Handler *AbstractHandler::SetNext(Handler *handler)
{
    this->next_handler_ = handler;
    // Returning a handler from here will let us link handlers in a convenient
    // way like this:
    // $monkey->setNext($squirrel)->setNext($dog);
    return handler;
}

std::string AbstractHandler::Handle(std::string request)
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle(request);
    }

    return {};
}