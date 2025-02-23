/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "ConcreteStateA.h"
#include "Context.h"

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	ConcreteStateA state_a{};

	Context ctx{&state_a};

	ctx.Request();
	ctx.Request();
	ctx.Request();
}
