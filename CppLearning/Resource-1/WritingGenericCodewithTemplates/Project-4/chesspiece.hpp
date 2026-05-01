#pragma once

#include "gamepiece.hpp"
#include <iostream>

class ChessPiece : public GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const override;
};