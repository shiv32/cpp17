#pragma once

#include "CherryTree.hpp"
#include "BingCherry.hpp"
#include <memory>

class BingCherryTree : public CherryTree
{

public:
    // virtual Cherry *pick() override;
    virtual BingCherry *pick() override;

    //compile error: invalid covariant return type for ‘virtual std::unique_ptr<BingCherry> BingCherryTree::pick()’
    //virtual std::unique_ptr<BingCherry> pick() override;
};