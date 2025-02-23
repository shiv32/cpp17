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

// g++ --std=c++17 *.cpp -o test && ./test && rm test

#include <cstdlib>

#include "Lamp.h"

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux
	
	Lamp lamp{};

	lamp.SwitchOn();

	lamp.SwitchOn();

	lamp.SwitchOff();

	lamp.SwitchOff();
}
