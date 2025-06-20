#pragma once

#include <memory>

class GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const = 0;
};