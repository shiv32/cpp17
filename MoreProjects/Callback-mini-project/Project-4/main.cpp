#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

int main()
{
    NumbersInput input{};

    Menu menu{};

    menu.RegisterPersistentHandler(&NumbersInput::OnDisplay); // member fun to fun pointer will not work
    menu.RegisterExitHandler(OnExit);

    menu.RegisterMenuItem("Generate random numbers", OnGenerateRandom);
    menu.RegisterMenuItem("Add a number", OnAdd);
    menu.RegisterMenuItem("Update a number", OnUpdate);
    menu.RegisterMenuItem("Insert a number", OnInsert);
    menu.RegisterMenuItem("Remove a number", OnRemove);
    menu.RegisterMenuItem("Remove all numbers", OnRemoveAll);

    menu.Run();

    return 0;
}