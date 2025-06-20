#pragma once

#include "Gregarious.hpp"

class Shy : public Gregarious
{
protected:
    virtual void talk() override;
};