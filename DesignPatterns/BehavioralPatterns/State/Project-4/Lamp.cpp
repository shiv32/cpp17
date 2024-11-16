#include "Lamp.h"
#include <cstdlib>
#include "OffState.h"

Lamp::Lamp()
{
	m_pState = new OffState{};
}

Lamp::~Lamp()
{
}

void Lamp::SwitchOn()
{
	m_pState->SwitchOn(this);
}

void Lamp::SwitchOff()
{
	m_pState->SwitchOff(this);
}

void Lamp::SetState(State *pState)
{
	m_pState = pState;
}
