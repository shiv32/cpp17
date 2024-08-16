/**
 * @file Base.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>

class Base
{
public:
    // void someMethod();
     virtual void someMethod(double d);

protected:
    int mProtectedInt{};

private:
    int mPrivateInt{};
};

// class Base final
// {
// public:
//     void someMethod();

// protected:
//     int mProtectedInt{};

// private:
//     int mPrivateInt{};
// };