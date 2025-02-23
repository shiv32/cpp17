/**
 * @file StateFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <string_view>

class State;

class StateFactory
{
public:
	static State *GetState(std::string_view stateType);
};
