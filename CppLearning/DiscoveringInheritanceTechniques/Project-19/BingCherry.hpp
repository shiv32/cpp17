#pragma once

#include <iostream>
#include "Cherry.hpp"

class BingCherry : public Cherry
{
public:
    void polish();
    virtual void printType() override;
};