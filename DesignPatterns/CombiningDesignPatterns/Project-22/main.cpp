#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

// ===== Interface: Command Pattern =====
class ITask
{
public:
    virtual void execute() = 0;
    virtual ~ITask() = default;
};

// ===== Concrete Task: Print Task =====
class PrintTask : public ITask
{
    std::function<void()> func;

public:
    PrintTask(std::function<void()> f) : func(std::move(f)) {}
    void execute() override
    {
        func();
    }
};

// ===== Observer Interface =====
class IObserver
{
public:
    virtual void onTaskExecuted(const std::string &msg) = 0;
    virtual ~IObserver() = default;
};

// ===== Concrete Observer =====
class Logger : public IObserver
{
public:
    void onTaskExecuted(const std::string &msg) override
    {
        std::cout << "[Logger] Task Completed: " << msg << std::endl;
    }
};

// ===== Factory: Creates Tasks =====
class TaskFactory
{
public:
    static std::shared_ptr<ITask> createPrintTask(const std::string &msg, std::shared_ptr<IObserver> observer = nullptr)
    {
        return std::make_shared<PrintTask>([msg, observer]()
                                           {
            std::cout << "[Task] " << msg << std::endl;
            if (observer) observer->onTaskExecuted(msg); });
    }

    static std::shared_ptr<ITask> createMathTask(int a, int b, std::shared_ptr<IObserver> observer = nullptr)
    {
        return std::make_shared<PrintTask>([a, b, observer]()
                                           {
            int result = a + b;
            std::cout << "[Task] " << a << " + " << b << " = " << result << std::endl;
            if (observer) observer->onTaskExecuted("MathTask: " + std::to_string(result)); });
    }
};

// ===== Singleton Scheduler =====
class Scheduler
{
    std::vector<std::shared_ptr<ITask>> tasks;

    Scheduler() = default;

public:
    static Scheduler &getInstance()
    {
        static Scheduler instance;
        return instance;
    }

    void addTask(std::shared_ptr<ITask> task)
    {
        tasks.push_back(std::move(task));
    }

    void run()
    {
        std::cout << "=== Running Scheduled Tasks ===\n";
        for (const auto &task : tasks)
        {
            task->execute();
        }
    }

    // Disable copy
    Scheduler(const Scheduler &) = delete;
    Scheduler &operator=(const Scheduler &) = delete;
};

// ===== Main Application =====
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "-----------(lambda fun version)--------------------" << std::endl;

    auto logger = std::make_shared<Logger>();
    auto &scheduler = Scheduler::getInstance();

    auto task1 = TaskFactory::createPrintTask("Hello from Task 1", logger);
    auto task2 = TaskFactory::createPrintTask("Executing Task 2", logger);
    auto task3 = TaskFactory::createMathTask(7, 8, logger);

    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);

    scheduler.run();

    return 0;
}
