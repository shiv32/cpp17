#include "chesspiece.hpp"

std::unique_ptr<GamePiece> ChessPiece::clone() const
{
    //std::cout<<__PRETTY_FUNCTION__<<std::endl;
    
    // Call the copy constructor to copy this instance
    return std::make_unique<ChessPiece>(*this);
}

void ChessPiece::status() 
{
    std::cout<<"pawn"<<std::endl;
}
