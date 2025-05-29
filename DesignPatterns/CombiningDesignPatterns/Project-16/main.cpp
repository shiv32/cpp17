#include "Observer.hpp"
#include "Singleton.hpp"
#include "Command.hpp"
#include <iostream>
#include <string>

// Define an event
struct SensorEvent
{
    std::string type;
    double value;
};

// Observer implementation
class SensorLogger : public Observer<SensorEvent>
{
public:
    void onNotify(const SensorEvent &e) override
    {
        std::cout << "[Logger] " << e.type << ": " << e.value << std::endl;
    }
};

// Command implementation
class LogCommand : public EventCommand<SensorEvent>
{
public:
    void execute(const SensorEvent &e) override
    {
        std::cout << "[Command] Executing log for " << e.type << " = " << e.value << std::endl;
    }
};

// Dispatcher using Singleton + Subject
class EventDispatcher : public Singleton<EventDispatcher>, public Subject<SensorEvent>
{
    friend class Singleton<EventDispatcher>;
};

// Main
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SensorLogger logger;
    LogCommand logCommand;

    auto &dispatcher = EventDispatcher::instance();
    dispatcher.addObserver(&logger);

    SensorEvent tempEvent{"Temperature", 24.5};
    dispatcher.notify(tempEvent);

    logCommand.execute(tempEvent);

    return 0;
}
