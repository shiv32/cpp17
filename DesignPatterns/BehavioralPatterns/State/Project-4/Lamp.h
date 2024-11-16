#pragma once

class State;

class Lamp
{
  State *m_pState{};

public:
  Lamp();
  ~Lamp();
  
  void SwitchOn();
  void SwitchOff();

  void SetState(State *pState);
};
