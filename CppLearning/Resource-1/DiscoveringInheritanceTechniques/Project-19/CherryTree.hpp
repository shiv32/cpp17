#pragma once

#include <memory>

class Cherry;

class CherryTree
{
public:
    virtual Cherry *pick();
    //virtual std::unique_ptr<Cherry> pick();
};