
#include "Context.hpp"
#include "Logger.hpp"
#include "StateLogger.hpp"
#include <iostream>

int main() {
    Logger::getInstance().log("Advanced State Machine App Started");

    Context context;
    StateLogger observer;
    context.attach(&observer);

    std::string input;
    
    while (true) {
        std::cout << "Enter command (start, complete, reset, quit): ";
        std::getline(std::cin, input);

        if (input == "quit") break;

        context.request(input);
    }

    context.detach(&observer);
    Logger::getInstance().log("App Exited");
    return 0;
}
