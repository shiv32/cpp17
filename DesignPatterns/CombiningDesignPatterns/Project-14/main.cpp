#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Strategy Pattern
class Formatter
{
public:
    virtual std::string format(const std::string &msg) = 0;
    virtual ~Formatter() = default;
};

class SimpleFormatter : public Formatter
{
public:
    std::string format(const std::string &msg) override
    {
        return msg;
    }
};

// Observer Pattern
class PrintObserver
{
public:
    virtual void onPrinted(const std::string &message) = 0;
    virtual ~PrintObserver() = default;
};

class ConsoleObserver : public PrintObserver
{
public:
    void onPrinted(const std::string &message) override
    {
        std::cout << "Observer: Message was printed.\n";
    }
};

// Singleton + Subject
class Printer
{
private:
    std::vector<PrintObserver *> observers;
    Printer() = default;

public:
    static Printer &getInstance()
    {
        static Printer instance;
        return instance;
    }

    void addObserver(PrintObserver *obs)
    {
        observers.push_back(obs);
    }

    void print(const std::string &message)
    {
        std::cout << message << std::endl;

        for (auto obs : observers)
        {
            obs->onPrinted(message);
        }
    }

    Printer(const Printer &) = delete;
    Printer &operator=(const Printer &) = delete;
};

// Factory Method
class Message
{
protected:
    std::string content;

public:
    Message(std::string text) : content(std::move(text)) {}
    std::string getContent() const { return content; }
};

class MessageFactory
{
public:
    static std::unique_ptr<Message> createMessage(std::string msg)
    {
        return std::make_unique<Message>(msg);
    }
};

// Command Pattern
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class PrintCommand : public Command
{
    Message *message;
    Formatter *formatter;

public:
    PrintCommand(Message *msg, Formatter *fmt) : message(msg), formatter(fmt) {}

    void execute() override
    {
        std::string formatted = formatter->format(message->getContent());
        Printer::getInstance().print(formatted);
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto message = MessageFactory::createMessage("Hello, Shiv !");

    SimpleFormatter formatter;
    ConsoleObserver observer;

    Printer::getInstance().addObserver(&observer);

    PrintCommand command(message.get(), &formatter);

    command.execute();

    return 0;
}
