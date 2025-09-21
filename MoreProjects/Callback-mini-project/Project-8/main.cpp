#include <iostream>
#include "Menu.hpp"
#include "NumbersInput.hpp"

int main()
{
    NumbersInput input{};

    Menu menu{&input};

    menu.RegisterPersistentHandler(&input); 
    menu.RegisterExitHandler(&input);

    menu.RegisterMenuItem("Generate random numbers",    &input);
    menu.RegisterMenuItem("Add a number",               &input);
    menu.RegisterMenuItem("Update a number",            &input); //bug
    menu.RegisterMenuItem("Insert a number",            &input);
    menu.RegisterMenuItem("Remove a number",            &input);
    menu.RegisterMenuItem("Remove all numbers",         &input);

    menu.Run();

    return 0;
}