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
