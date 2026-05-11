#include "ticTacToePiece.hpp"
#include <iostream>

std::unique_ptr<GamePiece> TicTacToePiece::clone() const
{
     std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Call the copy constructor to copy this instance
    return std::make_unique<TicTacToePiece>(*this);
}