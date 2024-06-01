#pragma once

#include "Handler.hpp"

/**
 * The default chaining behavior can be implemented inside a base handler class.
 */
class AbstractHandler : public Handler
{
    /**
     * @var Handler
     */
private:
    Handler *next_handler_;

public:
    AbstractHandler();
    Handler *SetNext(Handler *handler) override;
    std::string Handle(std::string request) override;
};