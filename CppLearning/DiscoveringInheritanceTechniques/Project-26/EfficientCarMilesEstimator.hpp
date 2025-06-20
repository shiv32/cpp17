#pragma once

#include "MilesEstimator.hpp"

class EfficientCarMilesEstimator : public MilesEstimator
{
private:
    virtual int getMilesPerGallon() const override;
};