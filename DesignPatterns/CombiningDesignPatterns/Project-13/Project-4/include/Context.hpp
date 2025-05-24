#pragma once
#include <string>
#include <vector>
#include <memory>
#include "State.hpp"
#include "States/Observer.hpp"
#include "States/Strategy.hpp"

class Context {
    State* currentState;
    std::vector<IObserver*> observers;
    std::unique_ptr<IExecutionStrategy> strategy;

public:
    Context(State* initState);
    void setState(State* state);
    void handle();
    void addObserver(IObserver* obs);
    void notifyObservers();
    void setStrategy(std::unique_ptr<IExecutionStrategy> strat);
    void executeStrategy();
    State* getState() const;
};
