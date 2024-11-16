#include "OffState.h"

#include <iostream>
#include "Lamp.h"
#include "StateFactory.h"

void OffState::SwitchOn(Lamp *pLamp)
{
	std::cout << "Turned On\n";
	
	pLamp->SetState(StateFactory::GetState("on_state"));
}

void OffState::SwitchOff(Lamp *pLamp)
{
	std::cout << "Already off\n";
}
