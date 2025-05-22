#include "CommandFactory.h"
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string cmd;

    while (true)
    {
        std::cout << "\nEnter command (add, update, delete, list, exit): ";

        std::cin >> cmd;

        if (cmd == "exit")
            break;

        auto command = CommandFactory::createCommand(cmd);

        if (command)
            command->execute();
        else
            std::cout << "Unknown command.\n";
    }
    
    return 0;
}
