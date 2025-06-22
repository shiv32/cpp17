/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief

    The Grid Class Definition
    The Grid Class Method Definitions
    Using the Grid Template

    g++ -std=c++17 *.cpp -o test

 * @version 0.1
 * @date 2025-03-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"
#include "chesspiece.hpp"
#include "spreadsheetCell.hpp"
#include <vector>
#include <memory>

using IntGrid = Grid<int>;

// void processIntGrid(Grid<int> &grid)
void processIntGrid(IntGrid &grid)
{
    int x = grid.at(0, 0).value_or(0);
    std::cout << "processIntGrid x : " << x << std::endl;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //---------- Using the Grid Template ---------------

    /*
     Grid test; // WILL NOT COMPILE
     Grid<> test; // WILL NOT COMPILE
    */

    Grid<int> myIntGrid; // declares a grid that stores ints,
                         // using default arguments for the constructor

    Grid<double> myDoubleGrid(11, 11); // declares an 11x11 Grid of doubles

    myIntGrid.at(0, 0) = 10;

    processIntGrid(myIntGrid);

    int x = myIntGrid.at(0, 0).value_or(0);

    std::cout << "x : " << x << std::endl;

    Grid<int> grid2(myIntGrid); // Copy constructor
    Grid<int> anotherIntGrid;

    anotherIntGrid = grid2; // Assignment operator

    //-------------------------------------------------------------
    IntGrid myIntGrid2;
    //-----------------------------------------------------------------
    Grid<SpreadsheetCell> mySpreadsheet;
    SpreadsheetCell myCell(1.234);
    // mySpreadsheet.at(3, 4) = myCell; //copy ctor
    mySpreadsheet.at(3, 4) = std::move(myCell); // move ctor
    std::cout << "mySpreadsheet value at (3,4) : " << mySpreadsheet.at(3, 4).value().getValue() << std::endl;

    // store pointer types
    Grid<const char *> myStringGrid;
    myStringGrid.at(2, 2) = "hello";
    std::cout << "myStringGrid value at (2,2) : " << myStringGrid.at(2, 2).value_or("") << std::endl;

    // The type specified can even be another template type
    Grid<std::vector<int>> gridOfVectors;
    std::vector<int> myVector{1, 2, 3, 4};
    gridOfVectors.at(5, 6) = myVector;

    for (const auto &value : gridOfVectors.at(5, 6).value())
    {
        std::cout << "gridOfVectors value at (5,6) : " << value << std::endl;
    }

    // dynamically allocate Grid template instantiations on the heap
    auto myGridOnHeap = std::make_unique<Grid<int>>(2, 2); // 2x2 Grid on the heap
    myGridOnHeap->at(0, 0) = 20;
    x = myGridOnHeap->at(0, 0).value_or(0);

    std::cout << "x : " << x << std::endl;
    //------------------------------------------------------------------

    Grid<ChessPiece> chessBoard(8, 8);
    
    ChessPiece king("King");
    ChessPiece queen("Queen");

    chessBoard.at(0, 0) = king;
    chessBoard.at(1, 1) = queen;

    std::cout << "chessBoard value at (0,0) : " << chessBoard.at(0, 0).value().getValue() << std::endl;
    std::cout << "chessBoard value at (1,1) : " << chessBoard.at(1, 1).value().getValue() << std::endl;

    return 0;
}