#pragma once
#include <vector>
#include <memory>
#include <iostream>

class ITaskComponent {
public:
    virtual void execute() = 0;
    virtual ~ITaskComponent() = default;
};

class Task : public ITaskComponent {
    std::string name;
public:
    Task(std::string n) : name(std::move(n)) {}
    void execute() override {
        std::cout << "Executing task: " << name << std::endl;
    }
};

class TaskGroup : public ITaskComponent {
    std::vector<std::shared_ptr<ITaskComponent>> children;
public:
    void add(std::shared_ptr<ITaskComponent> task) {
        children.push_back(std::move(task));
    }

    void execute() override {
        for (auto& child : children)
            child->execute();
    }
};