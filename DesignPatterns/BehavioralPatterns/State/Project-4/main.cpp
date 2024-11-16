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
