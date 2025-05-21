
#pragma once
#include "TaskFactory.h"
#include "TaskManager.h"

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class AddTaskCommand : public Command {
public:
    void execute() override {
        std::string desc;
        std::cout << "Enter task description: ";
        std::getline(std::cin, desc);
        auto task = TaskFactory::createSimpleTask(desc);
        TaskManager::getInstance().addTask(task);
    }
};

class ListTasksCommand : public Command {
public:
    void execute() override {
        TaskManager::getInstance().listTasks();
    }
};
