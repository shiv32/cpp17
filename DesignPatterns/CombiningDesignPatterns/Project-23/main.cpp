#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <mutex>

// ------------------- Singleton (Logger) -------------------
class Logger
{
public:
    static Logger &instance()
    {
        static Logger instance;
        return instance;
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

// ------------------- Observer Pattern -------------------
class IObserver
{
public:
    virtual void onProcessComplete(const std::string &msg) = 0;
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
    void notify(const std::string &msg)
    {
        for (auto *obs : observers_)
            obs->onProcessComplete(msg);
    }

private:
    std::vector<IObserver *> observers_;
};

// ------------------- Template Method + Strategy -------------------
template <typename T>
class IProcessor : public Subject
{
public:
    virtual ~IProcessor() = default;

    void process(const T &input)
    {
        Logger::instance().log("Start processing...");
        preprocess(input);
        execute(input);
        postprocess(input);
        notify("Processing complete");
    }

protected:
    virtual void preprocess(const T &) {}
    virtual void execute(const T &) = 0;
    virtual void postprocess(const T &) {}
};

// ------------------- Concrete Processors -------------------
class IntProcessor : public IProcessor<int>
{
protected:
    void execute(const int &input) override
    {
        std::cout << "Int Square: " << input * input << std::endl;
    }
};

class FloatProcessor : public IProcessor<float>
{
protected:
    void execute(const float &input) override
    {
        std::cout << "Float Half: " << input / 2.0f << std::endl;
    }
};

class StringProcessor : public IProcessor<std::string>
{
protected:
    void execute(const std::string &input) override
    {
        std::cout << "Reversed String: ";
        for (auto it = input.rbegin(); it != input.rend(); ++it)
            std::cout << *it;
        std::cout << std::endl;
    }
};

// ------------------- Factory Method -------------------
class ProcessorFactory
{
public:
    template <typename T>
    static std::unique_ptr<IProcessor<T>> create(const std::string &type)
    {
        if (type == "int")
        {
            if constexpr (std::is_same<T, int>::value)
                return std::make_unique<IntProcessor>();
        }
        else if (type == "float")
        {
            if constexpr (std::is_same<T, float>::value)
                return std::make_unique<FloatProcessor>();
        }
        else if (type == "string")
        {
            if constexpr (std::is_same<T, std::string>::value)
                return std::make_unique<StringProcessor>();
        }

        return nullptr;
    }
};

// ------------------- Example Observer -------------------
class ConsoleObserver : public IObserver
{
public:
    void onProcessComplete(const std::string &msg) override
    {
        std::cout << "[Observer] " << msg << std::endl;
    }
};

// ------------------- Main -------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ConsoleObserver observer;

    auto intProc = ProcessorFactory::create<int>("int");
    if (intProc)
    {
        intProc->attach(&observer);
        intProc->process(7);
    }

    auto floatProc = ProcessorFactory::create<float>("float");
    if (floatProc)
    {
        floatProc->attach(&observer);
        floatProc->process(4.2f);
    }

    auto stringProc = ProcessorFactory::create<std::string>("string");
    if (stringProc)
    {
        stringProc->attach(&observer);
        stringProc->process("hello");
    }

    return 0;
}
