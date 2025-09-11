#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <memory>
#include <utility>
#include "chess_types.hpp"
#include "piece.hpp"

constexpr int BOARD_SIZE = 8;

class Board {
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> board_;

public:
    Board();
    void initializeBoard();
    void display() const;
    const Piece* getPiece(int row, int col) const;
    bool isValidPosition(int row, int col) const;
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
};

#endif // BOARD_HPP
