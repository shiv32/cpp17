
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Task.h"
#include "TaskFactory.h"

class TaskManager
{
    std::vector<std::shared_ptr<Task>> tasks;
    static TaskManager *instance;

    TaskManager() = default;

public:
    static TaskManager &getInstance()
    {
        if (!instance)
            instance = new TaskManager();

        return *instance;
    }

    void addTask(std::shared_ptr<Task> task)
    {
        tasks.push_back(task);
        std::cout << "Task added.\n";
    }

    void listTasks() const
    {
        // for (const auto &task : tasks)
        //     task->display();

        auto comTask = TaskFactory::createCompositeTask("Task");

        for (const auto &task : tasks)
        {
            comTask->addTask(task);
        }

        comTask->display();
    }
};

TaskManager *TaskManager::instance = nullptr;
