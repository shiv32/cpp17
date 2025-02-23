/**
 * @file Context.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

class State;

class Context
{
	State *m_pState{};

public:
	Context(State *pState);
	void Request();
};
