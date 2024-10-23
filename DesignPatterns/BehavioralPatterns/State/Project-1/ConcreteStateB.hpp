#pragma once

#include "State.hpp"

class ConcreteStateB : public State {
 public:
     void Handle1() override;
     void Handle2() override;
};