#pragma once

#include "gamepiece.hpp"

class ChessPiece : public GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const override;
};