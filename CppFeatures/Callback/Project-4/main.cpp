/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Member function as callback
 *
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Button.hpp"

class MyHandler
{
public:
    void OnClick()
    {
        std::cout << "Clicked." << std::endl;
    }

    void OnPressed()
    {
        std::cout << "Pressed." << std::endl;
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MyHandler handler;

    Button<MyHandler> btn{&handler, &MyHandler::OnClick};
    btn.GenerateEvent();

    Button<MyHandler> btn2{&handler, &MyHandler::OnPressed};
    btn2.GenerateEvent();

    return 0;
}