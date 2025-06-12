
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Task
{
public:
    virtual void addTask(std::shared_ptr<Task> task) = 0;
    virtual void display(int indent = 0) const = 0;
    virtual ~Task() = default;
};

class SimpleTask : public Task
{
    std::string description;

public:
    SimpleTask(const std::string &desc) : description(desc) {}

    void addTask(std::shared_ptr<Task> task) override {};

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "- " << description << "\n";
    }
};

class CompositeTask : public Task
{
    std::string name;
    std::vector<std::shared_ptr<Task>> subtasks;

public:
    CompositeTask(const std::string &name) : name(name) {}

    void addTask(std::shared_ptr<Task> task) override
    {
        subtasks.push_back(task);
    }

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "+ " << name << "\n";

        for (const auto &task : subtasks)
        {
            task->display(indent + 2);
        }
    }
};
