#include "Context.hpp"
#include <iostream>

Context::Context(State* initState) : currentState(initState) {}

void Context::setState(State* state) {
    currentState = state;
    notifyObservers();
}

void Context::handle() {
    if (currentState)
        currentState->handle(*this);
}

void Context::addObserver(IObserver* obs) {
    observers.push_back(obs);
}

void Context::notifyObservers() {
    for (auto* obs : observers)
        obs->onStateChanged(currentState->name());
}

void Context::setStrategy(std::unique_ptr<IExecutionStrategy> strat) {
    strategy = std::move(strat);
}

void Context::executeStrategy() {
    if (strategy)
        strategy->execute();
}

State* Context::getState() const {
    return currentState;
}