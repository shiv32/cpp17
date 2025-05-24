#pragma once
#include "Entity.hpp"

class Player : public Entity
{
public:
    void update() override;
    void render() override;
};
