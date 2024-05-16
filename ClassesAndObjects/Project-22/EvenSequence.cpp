#include "EvenSequence.hpp"

EvenSequence::EvenSequence(std::initializer_list<double> args)
{
    if (args.size() % 2 != 0)
    {
        throw std::invalid_argument("initializer_list should contain even number of elements.");
    }

    /*
    mSequence.reserve(args.size());

    for (const auto &value : args)
    {
        mSequence.push_back(value);
    }
    */

    mSequence.assign(args);
}

void EvenSequence::dump() const
{
    for (const auto &value : mSequence)
    {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}