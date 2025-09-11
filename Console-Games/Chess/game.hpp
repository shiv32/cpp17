#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "board.hpp"
#include "piece.hpp"

class Game {
private:
    Board board_;
    Color currentPlayer_;

    bool parseMove(const std::string& input, int& fromRow, int& fromCol, int& toRow, int& toCol) {
        if (input.length() != 4) return false;
        
        fromRow = input[0] - '0';
        fromCol = input[1] - '0';
        toRow = input[2] - '0';
        toCol = input[3] - '0';
        
        return board_.isValidPosition(fromRow, fromCol) && 
               board_.isValidPosition(toRow, toCol);
    }

    bool validateMove(int fromRow, int fromCol, int toRow, int toCol) {
        const Piece* piece = board_.getPiece(fromRow, fromCol);
        if (!piece || piece->getType() == PieceType::EMPTY || piece->getColor() != currentPlayer_) {
            return false;
        }
        
        const Piece* targetPiece = board_.getPiece(toRow, toCol);
        if (targetPiece && targetPiece->getColor() == currentPlayer_) {
            return false;
        }
        
        return true;
    }

public:
    Game() : currentPlayer_(Color::WHITE) {}

    void play() {
        std::string input;
        bool gameRunning = true;

        while (gameRunning) {
            board_.display();
            
            std::cout << "\nCurrent player: " 
                      << (currentPlayer_ == Color::WHITE ? "White" : "Black")
                      << "\nEnter move (fromRow fromCol toRow toCol, e.g., 6032): ";
            
            std::getline(std::cin, input);
            if (input == "quit") break;

            int fromRow, fromCol, toRow, toCol;
            if (!parseMove(input, fromRow, fromCol, toRow, toCol)) {
                std::cout << "Invalid input format!\n";
                continue;
            }

            if (!validateMove(fromRow, fromCol, toRow, toCol)) {
                std::cout << "Invalid move: You can only move your own pieces!\n";
                continue;
            }

            if (board_.movePiece(fromRow, fromCol, toRow, toCol)) {
                currentPlayer_ = (currentPlayer_ == Color::WHITE) ? Color::BLACK : Color::WHITE;
            } else {
                std::cout << "Invalid move!\n";
            }
        }
    }
};

#endif // GAME_HPP
