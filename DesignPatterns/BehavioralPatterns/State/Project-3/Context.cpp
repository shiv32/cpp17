/**
 * @file Context.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Context.h"
#include "State.h"

Context::Context(State *pState) : m_pState(pState)
{
}

void Context::Request()
{
	m_pState = m_pState->Handle();
}
