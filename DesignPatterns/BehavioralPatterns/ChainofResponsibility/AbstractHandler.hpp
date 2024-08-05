/**
 * @file AbstractHandler.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "Handler.hpp"
#include <iostream>

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
    void HandlerName() override;
    Handler *SetNext(Handler *handler) override;
    std::string Handle(std::string request) override;
};