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

// ===== Concrete Task =====
class FunctionTask : public ITask
{
    std::function<void()> func;

public:
    FunctionTask(std::function<void()> f) : func(std::move(f)) {}

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

// ===== Factory using std::bind =====
class TaskFactory
{
public:
    static void printMessage(const std::string &msg, std::shared_ptr<IObserver> obs)
    {
        std::cout << "[Task] " << msg << std::endl;

        if (obs)
            obs->onTaskExecuted(msg);
    }

    static void addNumbers(int a, int b, std::shared_ptr<IObserver> obs)
    {
        int result = a + b;

        std::cout << "[Task] Sum = " << result << std::endl;

        if (obs)
            obs->onTaskExecuted("MathTask: " + std::to_string(result));
    }

    static std::shared_ptr<ITask> createPrintTask(const std::string &msg, std::shared_ptr<IObserver> obs)
    {
        return std::make_shared<FunctionTask>(
            std::bind(&TaskFactory::printMessage, msg, obs));
    }

    static std::shared_ptr<ITask> createMathTask(int a, int b, std::shared_ptr<IObserver> obs)
    {
        return std::make_shared<FunctionTask>(
            std::bind(&TaskFactory::addNumbers, a, b, obs));
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

    std::cout << "-----------(std::bind version)--------------------" << std::endl;

    auto logger = std::make_shared<Logger>();
    auto &scheduler = Scheduler::getInstance();

    auto task1 = TaskFactory::createPrintTask("Hello from Task 1", logger);
    auto task2 = TaskFactory::createPrintTask("Running Task 2", logger);
    auto task3 = TaskFactory::createMathTask(10, 25, logger);

    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);

    scheduler.run();

    return 0;
}
