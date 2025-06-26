#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>

// ===== Strategy Interface =====
struct LogStrategy
{
    virtual void write(const std::string &message) = 0;
    virtual ~LogStrategy() = default;
};

// ===== Concrete Strategy: Console =====
class ConsoleStrategy : public LogStrategy
{
public:
    void write(const std::string &message) override
    {
        std::cout << message << std::endl;
    }
};

// ===== Concrete Strategy: File =====
class FileStrategy : public LogStrategy
{
    std::ofstream out;

public:
    FileStrategy(const std::string &filename)
    {
        out.open(filename, std::ios::app);
    }
    void write(const std::string &message) override
    {
        if (out.is_open())
        {
            out << message << std::endl;
        }
    }
    ~FileStrategy()
    {
        if (out.is_open())
            out.close();
    }
};

// ===== Decorator Pattern: Timestamp =====
class TimeStampDecorator : public LogStrategy
{
    std::unique_ptr<LogStrategy> wrappee;

public:
    TimeStampDecorator(std::unique_ptr<LogStrategy> strategy)
        : wrappee(std::move(strategy)) {}

    void write(const std::string &message) override
    {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timeStr = std::ctime(&now);
        timeStr.pop_back(); // remove newline
        wrappee->write("[" + timeStr + "] " + message);
    }
};

// ===== Singleton Logger with Variadic Template =====
class Logger
{
    std::unique_ptr<LogStrategy> strategy;

    Logger() = default;

public:
    // No copy
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static Logger &get()
    {
        static Logger instance;
        return instance;
    }

    void setStrategy(std::unique_ptr<LogStrategy> s)
    {
        strategy = std::move(s);
    }

    template <typename... Args>
    void log(Args &&...args)
    {
        std::ostringstream oss;
        (oss << ... << args); // C++17 fold expression
        if (strategy)
            strategy->write(oss.str());
    }
};

// ===== Main (Usage Example) =====
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Use console + timestamp
    auto strategy = std::make_unique<TimeStampDecorator>(std::make_unique<ConsoleStrategy>());
    Logger::get().setStrategy(std::move(strategy));

    Logger::get().log("Application started, PID: ", 1234);
    Logger::get().log("User ", "admin", " logged in.");
    Logger::get().log("CPU Usage: ", 75.6, "%");

    // Switch to file logging
    auto fileStrategy = std::make_unique<TimeStampDecorator>(std::make_unique<FileStrategy>("log.txt"));
    Logger::get().setStrategy(std::move(fileStrategy));

    Logger::get().log("This goes to file.");
    Logger::get().log("Shutting down at ", __TIME__);

    return 0;
}
