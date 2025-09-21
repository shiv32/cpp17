#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

struct ExitCommand : public BaseHandler
{
    bool OnExit() override
    {
        std::clog << "Exit the app.\n";
        return true;
    }
};

bool DoExit()
{
    std::clog << "Exit the app.\n";
    return true;
}

int main()
{
    NumbersInput input{};
    Menu menu{&input};
    ExitCommand ec{};

    menu.RegisterPersistentHandler(&input);
    // menu.RegisterExitHandler(&input);
    // menu.RegisterExitHandler(DoExit());
    menu.RegisterExitHandler(&ec);

    menu.RegisterMenuItem("Generate random numbers", &input);
    menu.RegisterMenuItem("Add a number", &input);
    menu.RegisterMenuItem("Update a number", &input); // bug
    menu.RegisterMenuItem("Insert a number", &input);
    menu.RegisterMenuItem("Remove a number", &input);
    menu.RegisterMenuItem("Remove all numbers", &input);

    menu.Run();

    return 0;
}