
#include "Context.hpp"
#include "Logger.hpp"
#include <iostream>

int main() {
    Logger::getInstance().log("State Machine App Started");

    Context context;
    std::string input;

    while (true) {
        std::cout << "Enter command (start, complete, reset, quit): ";
        std::getline(std::cin, input);

        if (input == "quit") break;

        context.request(input);
    }

    Logger::getInstance().log("App Exited");
    return 0;
}
