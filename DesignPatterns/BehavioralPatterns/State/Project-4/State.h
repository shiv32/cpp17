/**
 * @file State.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <iostream>

class Lamp;

class State
{
public:
	virtual void SwitchOn(Lamp *pLamp) = 0;
	virtual void SwitchOff(Lamp *pLamp) = 0;

	virtual ~State()
	{
		std::cout << __PRETTY_FUNCTION__ << '\n';
	}
};
