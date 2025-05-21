
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "TaskManager.h"
#include "Commands.h"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::map<int, std::unique_ptr<Command>> commands;
    commands[1] = std::make_unique<AddTaskCommand>();
    commands[2] = std::make_unique<ListTasksCommand>();

    while (true)
    {
        std::cout << "\n1. Add Task\n2. List Tasks\n0. Exit\n> ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0)
            break;
        if (commands.find(choice) != commands.end())
            commands[choice]->execute();
        else
            std::cout << "Invalid choice.\n";
    }

    return 0;
}
