/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    A Template Grid Class
    g++ -std=c++17 *.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-03-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "gameboard.hpp"
#include "chesspiece.hpp"
#include "ticTacToePiece.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << "----------------(1)----------------------" << std::endl;
    GameBoard chessBoard(8, 8);

    std::cout << "----------------(2)----------------------" << std::endl;
    chessBoard.at(0, 0) = std::make_unique<ChessPiece>();

    std::cout << "----------------(3)----------------------" << std::endl;
    chessBoard.at(0, 1) = std::make_unique<TicTacToePiece>(); //issue, chessBoard not seems to accept TicTacToePiece

    return 0;
}