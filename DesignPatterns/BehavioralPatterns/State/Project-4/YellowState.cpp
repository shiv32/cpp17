/**
 * @file YellowState.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "YellowState.h"
#include "Lamp.h"
#include "StateFactory.h"

void YellowState::SwitchOn(Lamp *pLamp)
{
	std::cout << "Setting to white light\n";
	pLamp->SetState(StateFactory::GetState("on_state"));
}

void YellowState::SwitchOff(Lamp *pLamp)
{
	std::cout << "Turned Off\n";
	pLamp->SetState(StateFactory::GetState("off_state"));
}
