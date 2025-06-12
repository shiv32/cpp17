
#pragma once
#include "Task.h"

class TaskFactory
{
public:
    static std::shared_ptr<Task> createSimpleTask(const std::string &desc)
    {
        return std::make_shared<SimpleTask>(desc);
    }

    static std::shared_ptr<Task> createCompositeTask(const std::string &name)
    {
        return std::make_shared<CompositeTask>(name);
    }
};
