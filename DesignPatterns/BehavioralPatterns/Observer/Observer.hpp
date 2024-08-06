/**
 * @file Observer.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include "IObserver.hpp"
#include "Subject.hpp"

class Observer : public IObserver
{
public:
    Observer(Subject &subject);
    ~Observer();

    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};
