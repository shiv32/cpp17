#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>
#include <sstream>
#include <functional>

// ---------- Logger (Singleton) ----------
class Logger
{
public:
    static Logger &instance()
    {
        static Logger logger;
        return logger;
    }

    void log(const std::string &msg)
    {
        std::lock_guard<std::mutex> lock(mu_);
        std::cout << "[LOG] " << msg << std::endl;
    }

private:
    Logger() = default;
    std::mutex mu_;
};

// ---------- Observer Pattern ----------
class IObserver
{
public:
    virtual void onTaskComplete(const std::string &taskName) = 0;
    virtual ~IObserver() = default;
};

class Subject
{
public:
    void attach(IObserver *obs)
    {
        observers_.push_back(obs);
    }

protected:
    void notify(const std::string &taskName)
    {
        for (auto *obs : observers_)
            obs->onTaskComplete(taskName);
    }

private:
    std::vector<IObserver *> observers_;
};

// ---------- Task<T> Base (Template Method + Template Class) ----------
template <typename T>
class Task : public Subject
{
public:
    Task(std::string name, T data) : name_(std::move(name)), data_(std::move(data)) {}
    virtual ~Task() = default;

    void run()
    {
        Logger::instance().log("Running task: " + name_);
        execute(data_);
        notify(name_);
    }

    const std::string &getName() const { return name_; }

protected:
    virtual void execute(const T &data) = 0;

private:
    std::string name_;
    T data_;
};

// ---------- Concrete Tasks (Strategy) ----------
class PrintTask : public Task<std::string>
{
public:
    PrintTask(const std::string &message) : Task("PrintTask", message) {}

protected:
    void execute(const std::string &msg) override
    {
        std::cout << "[Print] " << msg << std::endl;
    }
};

class WaitTask : public Task<int>
{
public:
    WaitTask(int seconds) : Task("WaitTask", seconds) {}

protected:
    void execute(const int &seconds) override
    {
        std::cout << "[Wait] Waiting for " << seconds << " seconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }
};

// ---------- Task Factory (Factory + Templated Payload Parsing) ----------
class TaskFactory
{
public:
    static std::unique_ptr<Task<std::string>> createPrintTask(const std::string &param)
    {
        return std::make_unique<PrintTask>(param);
    }

    static std::unique_ptr<Task<int>> createWaitTask(const std::string &param)
    {
        return std::make_unique<WaitTask>(std::stoi(param));
    }
};

// ---------- Console Observer ----------
class ConsoleObserver : public IObserver
{
public:
    void onTaskComplete(const std::string &taskName) override
    {
        std::cout << "[Observer] Task Completed: " << taskName << std::endl;
    }
};

// ---------- Main ----------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ConsoleObserver observer;

    auto task1 = TaskFactory::createPrintTask("Starting system backup...");
    auto task2 = TaskFactory::createWaitTask("2");
    auto task3 = TaskFactory::createPrintTask("Backup complete!");

    // Attach observer to each task individually (no initializer_list)
    task1->attach(&observer);
    task2->attach(&observer);
    task3->attach(&observer);

    // Use std::function to store callable tasks
    std::vector<std::function<void()>> tasks;
    tasks.push_back([&]()
                    { task1->run(); });
    tasks.push_back([&]()
                    { task2->run(); });
    tasks.push_back([&]()
                    { task3->run(); });

    for (auto &t : tasks)
        t();

    return 0;
}
