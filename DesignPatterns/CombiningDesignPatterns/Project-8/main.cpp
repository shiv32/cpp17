/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
    Chatbot with Intent Handling
    
    Patterns: Chain of Responsibility, Strategy, Command, Factory
 * 
 * 
 * 
 * @version 0.1
 * @date 2025-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// ------------------- Command -------------------
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class GreetCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Hello! How can I help you today?\n";
    }
};

class TimeCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "I'm not a real clock, but it's always time to code!\n";
    }
};

class FallbackCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Sorry, I didn't understand that.\n";
    }
};

// ------------------- Strategy -------------------
class ReplyStyle
{
public:
    virtual std::string format(const std::string &msg) = 0;
    virtual ~ReplyStyle() = default;
};

class FormalStyle : public ReplyStyle
{
public:
    std::string format(const std::string &msg) override
    {
        return "[Formal Reply] " + msg;
    }
};

class CasualStyle : public ReplyStyle
{
public:
    std::string format(const std::string &msg) override
    {
        return "Yo! " + msg;
    }
};

// ------------------- Intent Handler (Chain of Responsibility) -------------------
class IntentHandler
{
protected:
    std::shared_ptr<IntentHandler> next;

public:
    virtual ~IntentHandler() = default;

    void setNext(std::shared_ptr<IntentHandler> n) { next = std::move(n); }

    virtual bool handle(const std::string &input, std::shared_ptr<Command> &outCmd)
    {
        if (next)
            return next->handle(input, outCmd);

        return false;
    }
};

class GreetingHandler : public IntentHandler
{
public:
    bool handle(const std::string &input, std::shared_ptr<Command> &outCmd) override
    {
        if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos)
        {
            outCmd = std::make_shared<GreetCommand>();

            return true;
        }

        return IntentHandler::handle(input, outCmd);
    }
};

class TimeHandler : public IntentHandler
{
public:
    bool handle(const std::string &input, std::shared_ptr<Command> &outCmd) override
    {
        if (input.find("time") != std::string::npos)
        {
            outCmd = std::make_shared<TimeCommand>();

            return true;
        }

        return IntentHandler::handle(input, outCmd);
    }
};

// ------------------- Factory -------------------
class IntentFactory
{
public:
    static std::shared_ptr<IntentHandler> createChain()
    {
        auto greet = std::make_shared<GreetingHandler>();
        auto time = std::make_shared<TimeHandler>();

        greet->setNext(time);

        return greet;
    }
};

// ------------------- Chatbot -------------------
class Chatbot
{
    std::shared_ptr<IntentHandler> rootHandler;
    std::unique_ptr<ReplyStyle> replyStyle;

public:
    Chatbot(std::unique_ptr<ReplyStyle> style)
        : rootHandler(IntentFactory::createChain()), replyStyle(std::move(style))
    {
    }

    void processInput(const std::string &input)
    {
        std::shared_ptr<Command> command;

        if (!rootHandler->handle(input, command))
        {
            command = std::make_shared<FallbackCommand>();
        }

        std::cout << replyStyle->format("");

        command->execute();
    }
};

// ------------------- Main -------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Chatbot bot(std::make_unique<CasualStyle>());
    // Chatbot bot(std::make_unique<FormalStyle>());

    std::vector<std::string> inputs = {
        "hi",
        "what time is it",
        "goodbye"};

    for (const auto &input : inputs)
    {
        std::cout << "> User: " << input << "\n";

        bot.processInput(input);
    }

    return 0;
}
