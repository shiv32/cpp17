// Microservices Simulator using multiple design patterns
// Patterns: Mediator, Observer, Chain of Responsibility, Singleton

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <functional>

//----------------------------------
// Observer Pattern
//----------------------------------
class IObserver
{
public:
    virtual void onNotify(const std::string &message) = 0;
    virtual ~IObserver() = default;
};

//----------------------------------
// Mediator Pattern (Singleton)
//----------------------------------
class Mediator
{
private:
    std::map<std::string, std::vector<IObserver *>> observers;
    Mediator() = default;

public:
    Mediator(const Mediator &) = delete;
    Mediator &operator=(const Mediator &) = delete;

    static Mediator &getInstance()
    {
        static Mediator instance;
        return instance;
    }

    void subscribe(const std::string &topic, IObserver *observer)
    {
        observers[topic].push_back(observer);
    }

    void publish(const std::string &topic, const std::string &message)
    {
        for (auto *observer : observers[topic])
        {
            observer->onNotify(message);
        }
    }
};

//----------------------------------
// Chain of Responsibility
//----------------------------------
class Handler
{
protected:
    std::shared_ptr<Handler> next;

public:
    virtual void handle(const std::string &request)
    {
        if (next)
            next->handle(request);
    }
    void setNext(std::shared_ptr<Handler> nextHandler)
    {
        next = nextHandler;
    }
    virtual ~Handler() = default;
};

class AuthHandler : public Handler
{
public:
    void handle(const std::string &request) override
    {
        std::cout << "[Auth] Processing: " << request << std::endl;
        if (request.find("auth") != std::string::npos)
        {
            std::cout << "[Auth] Authentication passed\n";
            Handler::handle(request);
        }
        else
        {
            std::cout << "[Auth] Authentication failed\n";
        }
    }
};

class ValidationHandler : public Handler
{
public:
    void handle(const std::string &request) override
    {
        std::cout << "[Validation] Validating: " << request << std::endl;
        if (request.length() > 5)
        {
            std::cout << "[Validation] Validation passed\n";
            Handler::handle(request);
        }
        else
        {
            std::cout << "[Validation] Validation failed\n";
        }
    }
};

class StorageHandler : public Handler
{
public:
    void handle(const std::string &request) override
    {
        std::cout << "[Storage] Saving data: " << request << std::endl;
    }
};

//----------------------------------
// Example Microservices
//----------------------------------
class LoggingService : public IObserver
{
public:
    void onNotify(const std::string &message) override
    {
        std::cout << "[Logger] Received: " << message << std::endl;
    }
};

class NotificationService : public IObserver
{
public:
    void onNotify(const std::string &message) override
    {
        std::cout << "[Notifier] Alert sent: " << message << std::endl;
    }
};

//----------------------------------
// Main Simulation
//----------------------------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Setup observers
    LoggingService logger;
    NotificationService notifier;

    Mediator &mediator = Mediator::getInstance();
    mediator.subscribe("requests", &logger);
    mediator.subscribe("requests", &notifier);

    // Setup Chain of Responsibility
    auto auth = std::make_shared<AuthHandler>();
    auto validation = std::make_shared<ValidationHandler>();
    auto storage = std::make_shared<StorageHandler>();

    auth->setNext(validation);
    validation->setNext(storage);

    // Simulate requests
    std::string request;
    while (true)
    {
        std::cout << "\nEnter request (or 'exit'): ";
        std::getline(std::cin, request);
        if (request == "exit")
            break;

        mediator.publish("requests", request);
        auth->handle(request);
    }

    return 0;
}
