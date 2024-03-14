/*
Deriving from Class Templates

g++ -std=c++17 main.cpp chesspiece.cpp -o test
*/

#include <iostream>
#include "grid.hpp"
#include "chesspiece.hpp"

int main()
{

    GameBoard<ChessPiece> chessBoard(8, 8);
    ChessPiece pawn;
    chessBoard.at(0, 0) = pawn;
    chessBoard.move(0, 0, 0, 1);

    return 0;
}