#pragma once
#include <iostream>

class IExecutionStrategy {
public:
    virtual void execute() = 0;
    virtual ~IExecutionStrategy() = default;
};

class SequentialStrategy : public IExecutionStrategy {
public:
    void execute() override {
        std::cout << "Executing tasks sequentially." << std::endl;
    }
};