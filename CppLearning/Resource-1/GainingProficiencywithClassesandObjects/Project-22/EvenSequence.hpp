#pragma once

#include <initializer_list>
#include <iostream>
#include <vector>

class EvenSequence
{
public:
    EvenSequence(std::initializer_list<double> args);
    void dump() const;

private:
    std::vector<double> mSequence;
};