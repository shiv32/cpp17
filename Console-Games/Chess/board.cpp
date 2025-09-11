#include <utility>
#include <memory>
#include <iostream>
#include "piece.hpp"
#include "pieces.hpp"
#include "empty_piece.hpp"
#include "board.hpp"

Board::Board() {
    // Initialize the board with proper dimensions
    board_.resize(BOARD_SIZE);
    for (auto& row : board_) {
        row.resize(BOARD_SIZE);
    }
    initializeBoard();
}

void Board::initializeBoard() {
    // Initialize empty squares
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board_[i][j] = std::make_unique<EmptyPiece>();
        }
    }

    // Initialize white pieces
    board_[7][0] = std::make_unique<Rook>(Color::WHITE);
    board_[7][1] = std::make_unique<Knight>(Color::WHITE);
    board_[7][2] = std::make_unique<Bishop>(Color::WHITE);
    board_[7][3] = std::make_unique<Queen>(Color::WHITE);
    board_[7][4] = std::make_unique<King>(Color::WHITE);
    board_[7][5] = std::make_unique<Bishop>(Color::WHITE);
    board_[7][6] = std::make_unique<Knight>(Color::WHITE);
    board_[7][7] = std::make_unique<Rook>(Color::WHITE);

    // Initialize white pawns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        board_[6][j] = std::make_unique<Pawn>(Color::WHITE);
    }

    // Initialize black pieces
    board_[0][0] = std::make_unique<Rook>(Color::BLACK);
    board_[0][1] = std::make_unique<Knight>(Color::BLACK);
    board_[0][2] = std::make_unique<Bishop>(Color::BLACK);
    board_[0][3] = std::make_unique<Queen>(Color::BLACK);
    board_[0][4] = std::make_unique<King>(Color::BLACK);
    board_[0][5] = std::make_unique<Bishop>(Color::BLACK);
    board_[0][6] = std::make_unique<Knight>(Color::BLACK);
    board_[0][7] = std::make_unique<Rook>(Color::BLACK);

    // Initialize black pawns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        board_[1][j] = std::make_unique<Pawn>(Color::BLACK);
    }
}

void Board::display() const {
    std::cout << "  0 1 2 3 4 5 6 7\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board_[i][j]->getSymbol() << " ";
        }
        std::cout << "\n";
    }
}

const Piece* Board::getPiece(int row, int col) const {
    if (!isValidPosition(row, col)) return nullptr;
    return board_[row][col].get();
}

bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    if (!isValidPosition(fromRow, fromCol) || !isValidPosition(toRow, toCol)) {
        return false;
    }

    std::vector<std::pair<int, int>> possibleMoves = 
        board_[fromRow][fromCol]->getPossibleMoves(fromRow, fromCol, *this);

    bool validMove = false;
    for (const auto& move : possibleMoves) {
        if (move.first == toRow && move.second == toCol) {
            validMove = true;
            break;
        }
    }

    if (!validMove) return false;

    board_[toRow][toCol] = std::move(board_[fromRow][fromCol]);
    board_[fromRow][fromCol] = std::make_unique<EmptyPiece>();
    
    return true;
}
