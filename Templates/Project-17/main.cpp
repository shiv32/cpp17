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

    //----------------------------------------------------------------
    GameBoard<int> myInt(8, 8);
    myInt.at(0, 0) = 2;

    std::cout << "(0,0) : "<< myInt.at(0, 0).value_or(0) << std::endl;

    myInt.move(0, 0, 0, 1);

    std::cout << "(0,0) : "<< myInt.at(0, 0).value_or(0) << std::endl;
    std::cout << "(0,1) : "<< myInt.at(0, 1).value_or(0) << std::endl;

    return 0;
}