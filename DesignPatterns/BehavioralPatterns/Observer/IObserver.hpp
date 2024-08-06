/**
 * @file IObserver.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};