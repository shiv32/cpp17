#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <utility>
#include <memory>
#include "chess_types.hpp"

class Board;

class Piece {
protected:
    Color color_;
    PieceType type_;

public:
    Piece(Color color = Color::NONE, PieceType type = PieceType::EMPTY)
        : color_(color), type_(type) {}
    
    virtual ~Piece() = default;

    Color getColor() const { return color_; }
    PieceType getType() const { return type_; }

    virtual std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const = 0;
    
    virtual char getSymbol() const {
        switch (type_) {
            case PieceType::KING:   return (color_ == Color::WHITE) ? 'K' : 'k';
            case PieceType::QUEEN:  return (color_ == Color::WHITE) ? 'Q' : 'q';
            case PieceType::ROOK:   return (color_ == Color::WHITE) ? 'R' : 'r';
            case PieceType::BISHOP: return (color_ == Color::WHITE) ? 'B' : 'b';
            case PieceType::KNIGHT: return (color_ == Color::WHITE) ? 'N' : 'n';
            case PieceType::PAWN:   return (color_ == Color::WHITE) ? 'P' : 'p';
            default:                return '.';
        }
    }
};

#endif // PIECE_HPP
