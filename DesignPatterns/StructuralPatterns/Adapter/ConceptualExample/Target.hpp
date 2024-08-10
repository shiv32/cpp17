/**
 * @file Target.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target
{
public:
    virtual ~Target() = default;
    virtual std::string Request() const;
};