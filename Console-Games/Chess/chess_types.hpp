#ifndef CHESS_TYPES_HPP
#define CHESS_TYPES_HPP

enum class PieceType {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    EMPTY
};

enum class Color {
    WHITE,
    BLACK,
    NONE
};

// Forward declarations
class Board;

#endif // CHESS_TYPES_HPP
