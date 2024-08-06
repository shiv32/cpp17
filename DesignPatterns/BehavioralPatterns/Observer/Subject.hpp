/**
 * @file Subject.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

#include <iostream>
#include <list>
#include "IObserver.hpp"
#include "ISubject.hpp"

class Subject : public ISubject
{
public:
    virtual ~Subject();

    /**
     * The subscription management methods.
     */
    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
    void Notify() override;

    void CreateMessage(std::string message);
    void HowManyObserver();

    /**
     * Usually, the subscription logic is only a fraction of what a Subject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic();

private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};