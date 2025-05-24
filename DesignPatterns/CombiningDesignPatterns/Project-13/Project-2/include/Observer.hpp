
#pragma once
#include <vector>
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& state) = 0;
};

class Subject {
public:
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify(const std::string& state);

private:
    std::vector<Observer*> observers_;
};
