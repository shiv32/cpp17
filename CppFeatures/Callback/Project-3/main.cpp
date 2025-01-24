/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief function pointers examples
 *
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Button.hpp"

void OnClick(void *)
{
    std::cout << "Button clicked." << std::endl;
}

void OnPress(void *)
{
    std::cout << "Button pressed." << std::endl;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Button btn{OnClick};
    btn.GenerateEvent();

    Button btn2{OnPress};
    btn2.GenerateEvent();

    return 0;
}