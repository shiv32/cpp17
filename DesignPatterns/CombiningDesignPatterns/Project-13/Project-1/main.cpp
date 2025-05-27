#include <iostream>
#include "Context.hpp"
#include "Logger.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Logger::getInstance().log("State Machine App Started");

    Context context;
    std::string input;

    while (true)
    {
        std::cout << "Enter command (start, complete, reset, quit): ";

        std::getline(std::cin, input);

        if (input == "quit")
            break;

        context.request(input);
    }

    Logger::getInstance().log("App Exited");

    return 0;
}
