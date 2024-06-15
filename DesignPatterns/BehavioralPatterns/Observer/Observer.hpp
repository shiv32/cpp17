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
