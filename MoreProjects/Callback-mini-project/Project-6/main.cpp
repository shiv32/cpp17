#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

int main()
{
    NumbersInput input{};

    Menu menu{&input};

    menu.RegisterPersistentHandler(reinterpret_cast<void(BaseHandler::*)(int)>(&NumbersInput::OnDisplay)); //ptr to mem fun
    menu.RegisterExitHandler(reinterpret_cast<bool(BaseHandler::*)()>(&NumbersInput::OnExit));

    menu.RegisterMenuItem("Generate random numbers",    HANDLER(&NumbersInput::OnGenerateRandom));
    menu.RegisterMenuItem("Add a number",               HANDLER(&NumbersInput::OnAdd));
    menu.RegisterMenuItem("Update a number",            HANDLER(&NumbersInput::OnUpdate)); //bug
    menu.RegisterMenuItem("Insert a number",            HANDLER(&NumbersInput::OnInsert));
    menu.RegisterMenuItem("Remove a number",            HANDLER(&NumbersInput::OnRemove));
    menu.RegisterMenuItem("Remove all numbers",         HANDLER(&NumbersInput::OnRemoveAll));

    menu.Run();

    return 0;
}