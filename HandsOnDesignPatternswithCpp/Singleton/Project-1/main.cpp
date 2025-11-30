#include <iostream>
#include <mutex>

class Logger
{

public:
    static Logger &instance()
    {
        // static Logger instance_;
        return instance_;
    }

    void LogError(const char *msg)
    {
        std::lock_guard<std::mutex> guard(lock_);
        std::cerr << "ERROR: " << msg << std::endl;
        ++error_count_;
    }

private:
    Logger() : error_count_(0)
    {
        std::clog << "Logger obj created." << std::endl;
    };

    ~Logger()
    {
        std::clog << "Logger obj destroyed." << std::endl;
    };

    Logger(const Logger &amp) = delete;
    Logger &operator=(const Logger &amp) = delete;

    static Logger instance_;
    std::mutex lock_;
    size_t error_count_;
};

Logger Logger::instance_; // REQUIRED definition

int main()
{
    //Logger::instance();
    Logger::instance().LogError("Unexpected NULL pointer");

    return 0;
}
