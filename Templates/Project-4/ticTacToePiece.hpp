#pragma once

#include "gamepiece.hpp"

class TicTacToePiece : public GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const override;
};