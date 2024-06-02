#include "AbstractHandler.hpp"

AbstractHandler::AbstractHandler() : next_handler_(nullptr)
{
}

void AbstractHandler::HandlerName()
{
     std::cout<<"AbstractHandler called !"<<std::endl;
}

Handler *AbstractHandler::SetNext(Handler *handler)
{
    handler->HandlerName();

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
        this->next_handler_->HandlerName();
        
        return this->next_handler_->Handle(request);
    }

    return {};
}