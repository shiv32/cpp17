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
class State
{
public:
	virtual State *Handle() = 0;
	virtual ~State() = default;
};
