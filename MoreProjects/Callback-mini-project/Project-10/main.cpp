#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

struct ExitCommand
{
    bool OnExit()
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
    Menu menu{};
    ExitCommand ec{};

    menu.RegisterPersistentHandler([&input](int)
                                   { input.OnDisplay(-1); });

    menu.RegisterExitHandler(DoExit);

    using namespace std::placeholders;
    // menu.RegisterMenuItem("Generate random numbers", std::bind(&NumbersInput::OnEvent, &input, _1));
    // menu.RegisterMenuItem("Add a number", std::bind(&NumbersInput::OnEvent, &input, _1));
    // menu.RegisterMenuItem("Update a number", std::bind(&NumbersInput::OnEvent, &input, _1)); // bug
    // menu.RegisterMenuItem("Insert a number", std::bind(&NumbersInput::OnEvent, &input, _1));
    // menu.RegisterMenuItem("Remove a number", std::bind(&NumbersInput::OnEvent, &input, _1));
    // menu.RegisterMenuItem("Remove all numbers", std::bind(&NumbersInput::OnEvent, &input, _1));

    menu.RegisterMenuItem("Generate random numbers", std::bind(&NumbersInput::OnGenerateRandom, &input, _1));
    menu.RegisterMenuItem("Add a number", std::bind(&NumbersInput::OnAdd, &input, _1));
    menu.RegisterMenuItem("Update a number", std::bind(&NumbersInput::OnUpdate, &input, _1)); // bug
    menu.RegisterMenuItem("Insert a number", std::bind(&NumbersInput::OnInsert, &input, _1));
    menu.RegisterMenuItem("Remove a number", std::bind(&NumbersInput::OnRemove, &input, _1));
    menu.RegisterMenuItem("Remove all numbers", std::bind(&NumbersInput::OnRemoveAll, &input, _1));

    menu.Run();

    return 0;
}