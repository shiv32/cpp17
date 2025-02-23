/**
 * @file YellowState.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "State.h"

class YellowState : public State
{
public:
	void SwitchOn(Lamp *pLamp) override;
	void SwitchOff(Lamp *pLamp) override;
};
