#include "ticTacToePiece.hpp"

std::unique_ptr<GamePiece> TicTacToePiece::clone() const
{
    // Call the copy constructor to copy this instance
    return std::make_unique<TicTacToePiece>(*this);
}