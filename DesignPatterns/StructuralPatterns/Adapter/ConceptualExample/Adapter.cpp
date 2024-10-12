/**
 * @file Adapter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Adapter.hpp"

//  Adapter::Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
Adapter::Adapter(std::shared_ptr<Adaptee> adaptee) : adaptee_(adaptee) {}

std::string Adapter::Request() const
{
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
}