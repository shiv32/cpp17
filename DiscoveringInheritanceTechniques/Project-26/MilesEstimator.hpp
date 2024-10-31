#pragma once

class MilesEstimator
{
public:
    virtual ~MilesEstimator() = default;
    virtual int getMilesLeft() const;
    virtual void setGallonsLeft(int gallons);
    virtual int getGallonsLeft() const;

private:
    int mGallonsLeft;
    virtual int getMilesPerGallon() const;
};