/**
 * @file Subject.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Subject.hpp"

Subject::~Subject()
{
    std::cout << "Goodbye, I was the Subject.\n";
}

void Subject::Attach(IObserver *observer)
{
    list_observer_.push_back(observer);
}

void Subject::Detach(IObserver *observer)
{
    list_observer_.remove(observer);
}

void Subject::Notify()
{
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void Subject::CreateMessage(std::string message = "Empty")
{
    this->message_ = message;
    Notify();
}

void Subject::HowManyObserver()
{
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

void Subject::SomeBusinessLogic()
{
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
}
