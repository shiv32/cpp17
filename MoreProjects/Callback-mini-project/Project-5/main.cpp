#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

int main()
{
    NumbersInput input{};

    Menu menu{&input};

    menu.RegisterPersistentHandler(&NumbersInput::OnDisplay); //ptr to mem fun
    menu.RegisterExitHandler(&NumbersInput::OnExit);

    menu.RegisterMenuItem("Generate random numbers", &NumbersInput::OnGenerateRandom);
    menu.RegisterMenuItem("Add a number", &NumbersInput::OnAdd);
    menu.RegisterMenuItem("Update a number", &NumbersInput::OnUpdate); //bug
    menu.RegisterMenuItem("Insert a number", &NumbersInput::OnInsert);
    menu.RegisterMenuItem("Remove a number", &NumbersInput::OnRemove);
    menu.RegisterMenuItem("Remove all numbers", &NumbersInput::OnRemoveAll);

    menu.Run();

    return 0;
}