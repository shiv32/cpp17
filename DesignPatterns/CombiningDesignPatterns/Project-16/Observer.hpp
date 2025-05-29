#pragma once
#include <vector>
#include <algorithm>

template<typename EventType>
class Observer {
public:
    virtual void onNotify(const EventType& event) = 0;
};

template<typename EventType>
class Subject {
    std::vector<Observer<EventType>*> observers;
public:
    void addObserver(Observer<EventType>* obs) {
        observers.push_back(obs);
    }

    void removeObserver(Observer<EventType>* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify(const EventType& event) {
        for (auto* obs : observers) {
            obs->onNotify(event);
        }
    }
};
