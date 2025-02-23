/**
 * @file OnState.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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
