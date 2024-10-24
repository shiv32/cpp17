/**
 * @file State.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>
#include <typeinfo>
#include "Context.hpp"

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
 */

class Context;

class State
{
    /**
     * @var Context
     */
protected:
    Context *context_;

public:
    virtual ~State();
    void set_context(Context *context);

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};