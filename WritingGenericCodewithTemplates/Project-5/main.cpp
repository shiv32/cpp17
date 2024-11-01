/*
The Grid Class Definition
The Grid Class Method Definitions
Using the Grid Template

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "grid.hpp"
#include "chesspiece.hpp"
#include "spreadsheetCell.hpp"
#include <vector>
#include <memory>

using IntGrid = Grid<int>;

int main()
{

    Grid<int> myIntGrid; // declares a grid that stores ints,
                         // using default arguments for the constructor

    Grid<double> myDoubleGrid(11, 11); // declares an 11x11 Grid of doubles

    myIntGrid.at(0, 0) = 10;

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
    mySpreadsheet.at(3, 4) = myCell;

    //store pointer types
    Grid<const char *> myStringGrid;
    myStringGrid.at(2, 2) = "hello";

    //The type specified can even be another template type
    Grid<std::vector<int>> gridOfVectors;
    std::vector<int> myVector{1, 2, 3, 4};
    gridOfVectors.at(5, 6) = myVector;

   //dynamically allocate Grid template instantiations on the heap
    auto myGridOnHeap = std::make_unique<Grid<int>>(2, 2); // 2x2 Grid on the heap
    myGridOnHeap->at(0, 0) = 10;
    x = myGridOnHeap->at(0, 0).value_or(0);
    //------------------------------------------------------------------

    Grid<ChessPiece> chessBoard(8, 8);
    ChessPiece king;
    chessBoard.at(0, 0) = king;

    return 0;
}