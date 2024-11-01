/*
A Template Grid Class
g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "gameboard.hpp"
#include "chesspiece.hpp"
#include "ticTacToePiece.hpp"

int main()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << "----------------(1)----------------------" << std::endl;
    GameBoard chessBoard(8, 8);

    std::cout << "----------------(2)----------------------" << std::endl;
    chessBoard.at(0, 0) = std::make_unique<ChessPiece>();
    std::cout << "----------------(3)----------------------" << std::endl;
    chessBoard.at(0, 1) = std::make_unique<TicTacToePiece>();

    return 0;
}