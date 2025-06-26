#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <mutex>
#include <functional>
#include <numeric>
#include <cmath>

// ----------------- Logger (Singleton) -----------------
class Logger
{
public:
    static Logger &instance()
    {
        static Logger inst;
        return inst;
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

// ----------------- Observer -----------------
class IObserver
{
public:
    virtual void onOperationFinished(const std::string &opName) = 0;
    virtual ~IObserver() = default;
};

// ----------------- Observer Impl -----------------
class ConsoleObserver : public IObserver
{
public:
    void onOperationFinished(const std::string &opName) override
    {
        std::cout << "[Observer] Operation completed: " << opName << std::endl;
    }
};

// ----------------- Strategy Base (CRTP) -----------------
template <typename T>
class Operation
{
public:
    virtual ~Operation() = default;
    virtual T compute(const std::vector<T> &data) = 0;
    virtual std::string name() const = 0;
};

// ----------------- Concrete Strategies -----------------
template <typename T>
class SumOp : public Operation<T>
{
public:
    T compute(const std::vector<T> &data) override
    {
        return std::accumulate(data.begin(), data.end(), T{0});
    }
    std::string name() const override { return "sum"; }
};

template <typename T>
class ProductOp : public Operation<T>
{
public:
    T compute(const std::vector<T> &data) override
    {
        return std::accumulate(data.begin(), data.end(), T{1}, std::multiplies<T>());
    }
    std::string name() const override { return "product"; }
};

template <typename T>
class AverageOp : public Operation<T>
{
public:
    T compute(const std::vector<T> &data) override
    {
        if (data.empty())
            return T{0};
        return std::accumulate(data.begin(), data.end(), T{0}) / static_cast<T>(data.size());
    }
    std::string name() const override { return "average"; }
};

// ----------------- Registry (Factory + Singleton) -----------------
template <typename T>
class OperationRegistry
{
public:
    static OperationRegistry &instance()
    {
        static OperationRegistry inst;
        return inst;
    }

    void registerOp(const std::string &name, std::unique_ptr<Operation<T>> op)
    {
        operations_[name] = std::move(op);
        Logger::instance().log("Registered operation: " + name);
    }

    Operation<T> *getOp(const std::string &name)
    {
        auto it = operations_.find(name);

        if (it != operations_.end())
            return it->second.get();

        return nullptr;
    }

private:
    OperationRegistry() = default;
    std::map<std::string, std::unique_ptr<Operation<T>>> operations_;
};

// ----------------- Execution Engine -----------------
template <typename T>
class Engine
{
public:
    void attachObserver(IObserver *obs)
    {
        observer_ = obs;
    }

    void run(const std::string &opName, const std::vector<T> &data)
    {
        Logger::instance().log("Running operation: " + opName);
        auto *op = OperationRegistry<T>::instance().getOp(opName);
        if (!op)
        {
            std::cerr << "Operation '" << opName << "' not found.\n";
            return;
        }
        T result = op->compute(data);
        std::cout << "[" << opName << "] Result: " << result << "\n";
        if (observer_)
            observer_->onOperationFinished(opName);
    }

private:
    IObserver *observer_ = nullptr;
};

// ----------------- Main -----------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Register operations
    OperationRegistry<float>::instance().registerOp("sum", std::make_unique<SumOp<float>>());
    OperationRegistry<float>::instance().registerOp("product", std::make_unique<ProductOp<float>>());
    OperationRegistry<float>::instance().registerOp("average", std::make_unique<AverageOp<float>>());

    // Observer setup
    ConsoleObserver observer;
    Engine<float> engine;
    engine.attachObserver(&observer);

    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f};

    engine.run("sum", data);     // Expected: 10
    engine.run("product", data); // Expected: 24
    engine.run("average", data); // Expected: 2.5

    return 0;
}
