#include "OnState.h"
#include <iostream>
#include "Lamp.h"
#include "StateFactory.h"

void OnState::SwitchOn(Lamp *pLamp)
{
	std::cout << "Switched to Yellow color\n";

	pLamp->SetState(StateFactory::GetState("yellow_state"));
}

void OnState::SwitchOff(Lamp *pLamp)
{
	std::cout << "Turned Off\n";
	
	pLamp->SetState(StateFactory::GetState("off_state"));
}
