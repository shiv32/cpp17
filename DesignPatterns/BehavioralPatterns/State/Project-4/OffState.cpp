/**
 * @file OffState.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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
