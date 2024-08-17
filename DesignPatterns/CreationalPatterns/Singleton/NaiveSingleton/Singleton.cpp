/**
 * @file Singleton.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Singleton.hpp"

Singleton *Singleton::singleton_ = nullptr;


Singleton::Singleton(const std::string value) : value_(value)
{
}

/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton::GetInstance(const std::string &value)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void Singleton::SomeBusinessLogic()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string Singleton::value() const
{
    return value_;
}