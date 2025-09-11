#ifndef EMPTY_PIECE_HPP
#define EMPTY_PIECE_HPP

#include <vector>
#include <utility>
#include "piece.hpp"

class EmptyPiece : public Piece {
public:
    EmptyPiece() : Piece(Color::NONE, PieceType::EMPTY) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int, int, Board&) const override {
        return {};
    }
};

#endif // EMPTY_PIECE_HPP
