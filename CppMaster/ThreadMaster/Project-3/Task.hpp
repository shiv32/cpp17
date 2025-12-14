#pragma once
#include <functional>
#include <string>

enum class TaskPriority
{
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
};

class Task
{
public:
    Task(int id,
         std::string name,
         TaskPriority priority,
         std::function<void()> func)
        : id_(id),
          name_(std::move(name)),
          priority_(priority),
          func_(std::move(func)) {}

    void execute() const
    {
        func_();
    }

    int id() const { return id_; }
    const std::string &name() const { return name_; }
    TaskPriority priority() const { return priority_; }

private:
    int id_;
    std::string name_;
    TaskPriority priority_;
    std::function<void()> func_;
};
