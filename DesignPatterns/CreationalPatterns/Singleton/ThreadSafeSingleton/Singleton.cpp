/**
 * @file Singleton.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Singleton.hpp"

/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

Singleton::Singleton(const std::string value) : value_(value)
{
}

/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton::GetInstance(const std::string &value)
{
    std::lock_guard<std::mutex> lock(mutex_);

    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void Singleton::SomeBusinessLogic()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string Singleton::value() const
{
    return value_;
}