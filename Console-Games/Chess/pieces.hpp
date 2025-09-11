#ifndef PIECES_HPP
#define PIECES_HPP

#include <vector>
#include <utility>
#include <cstdlib>
#include "piece.hpp"
#include "board.hpp"

// Pawn piece
class Pawn : public Piece {
public:
    Pawn(Color color) : Piece(color, PieceType::PAWN) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        int direction = (color_ == Color::WHITE) ? -1 : 1;
        
        // Forward move
        if (board.isValidPosition(row + direction, col)) {
            const Piece* target = board.getPiece(row + direction, col);
            if (!target || target->getType() == PieceType::EMPTY) {
                moves.emplace_back(row + direction, col);
                
                // Initial two-square move
                if ((color_ == Color::WHITE && row == 6) || (color_ == Color::BLACK && row == 1)) {
                    if (board.isValidPosition(row + 2 * direction, col)) {
                        target = board.getPiece(row + 2 * direction, col);
                        if (!target || target->getType() == PieceType::EMPTY) {
                            moves.emplace_back(row + 2 * direction, col);
                        }
                    }
                }
            }
        }
        
        // Diagonal captures
        for (int dc : {-1, 1}) {
            if (board.isValidPosition(row + direction, col + dc)) {
                const Piece* target = board.getPiece(row + direction, col + dc);
                if (target && target->getType() != PieceType::EMPTY && target->getColor() != color_) {
                    moves.emplace_back(row + direction, col + dc);
                }
            }
        }
        
        return moves;
    }
};

// Rook piece
class Rook : public Piece {
public:
    Rook(Color color) : Piece(color, PieceType::ROOK) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (const auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];
            
            while (board.isValidPosition(r, c)) {
                const Piece* target = board.getPiece(r, c);
                if (!target || target->getType() == PieceType::EMPTY) {
                    moves.emplace_back(r, c);
                } else {
                    if (target->getColor() != color_) {
                        moves.emplace_back(r, c);
                    }
                    break;
                }
                r += dir[0];
                c += dir[1];
            }
        }
        
        return moves;
    }
};

// Knight piece
class Knight : public Piece {
public:
    Knight(Color color) : Piece(color, PieceType::KNIGHT) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        const int moves_pattern[8][2] = {
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
        };
        
        for (const auto& pattern : moves_pattern) {
            int r = row + pattern[0];
            int c = col + pattern[1];
            
            if (board.isValidPosition(r, c)) {
                const Piece* target = board.getPiece(r, c);
                if (!target || target->getType() == PieceType::EMPTY || target->getColor() != color_) {
                    moves.emplace_back(r, c);
                }
            }
        }
        
        return moves;
    }
};

// Bishop piece
class Bishop : public Piece {
public:
    Bishop(Color color) : Piece(color, PieceType::BISHOP) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        const int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        for (const auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];
            
            while (board.isValidPosition(r, c)) {
                const Piece* target = board.getPiece(r, c);
                if (!target || target->getType() == PieceType::EMPTY) {
                    moves.emplace_back(r, c);
                } else {
                    if (target->getColor() != color_) {
                        moves.emplace_back(r, c);
                    }
                    break;
                }
                r += dir[0];
                c += dir[1];
            }
        }
        
        return moves;
    }
};

// Queen piece
class Queen : public Piece {
public:
    Queen(Color color) : Piece(color, PieceType::QUEEN) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        const int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        for (const auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];
            
            while (board.isValidPosition(r, c)) {
                const Piece* target = board.getPiece(r, c);
                if (!target || target->getType() == PieceType::EMPTY) {
                    moves.emplace_back(r, c);
                } else {
                    if (target->getColor() != color_) {
                        moves.emplace_back(r, c);
                    }
                    break;
                }
                r += dir[0];
                c += dir[1];
            }
        }
        
        return moves;
    }
};

// King piece
class King : public Piece {
public:
    King(Color color) : Piece(color, PieceType::KING) {}
    
    std::vector<std::pair<int, int>> getPossibleMoves(int row, int col, Board& board) const override {
        std::vector<std::pair<int, int>> moves;
        const int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        for (const auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];
            
            if (board.isValidPosition(r, c)) {
                const Piece* target = board.getPiece(r, c);
                if (!target || target->getType() == PieceType::EMPTY || target->getColor() != color_) {
                    moves.emplace_back(r, c);
                }
            }
        }
        
        return moves;
    }
};

#endif // PIECES_HPP
